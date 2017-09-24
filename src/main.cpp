#include "common.h"

#include "UpdateController.h"
#include "I2cController.h"
#include "UpdateHandler.h"
#include "ArduinoHandler.h"
#include "DataHandler.h"
#include "CommandHandler.h"
#include "Supervisor.h"
#include "DataWorker.h"
#include "CommandWorker.h"
#include "ModuleHandler.h"
#include "ManagementModule.h"
#include "UpdateModule.h"
#include "DataModule.h"
#include "ComfortModule.h"
#include "Server.h"

int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);
	qDebug() << "qt-vec-api started...";

	UpdateController updateController;
	I2cController i2cController;
	if (! i2cController.init()) {
		qDebug() << "Failed to start I2C controller.";
		exit(1);
	}

	UpdateHandler updateHandler(&updateController);
	ArduinoHandler arduinoHandler(&i2cController, &updateHandler);
	DataHandler dataHandler(&updateHandler, &arduinoHandler);
	CommandHandler commandHandler(&updateHandler, &arduinoHandler);
	
	SupervisorThread supervisorThread;
	Supervisor supervisor(&i2cController, &updateHandler, &arduinoHandler);
	supervisor.moveToThread(&supervisorThread);
	supervisorThread.start();

	DataWorkerThread dataWorkerThread;
	DataWorker dataWorker(&updateHandler, &dataHandler);
	dataWorker.run(&dataWorkerThread);

	CommandWorkerThread commandWorkerThread;
	CommandWorker commandWorker(&updateHandler, &commandHandler);
	commandWorker.moveToThread(&commandWorkerThread);
	commandWorkerThread.start();

	ModuleHandler moduleHandler(&updateHandler, &dataWorker, &commandWorker);
	moduleHandler.registerModule("management", new ManagementModule(&arduinoHandler));
	moduleHandler.registerModule("update", new UpdateModule(&updateHandler));
	moduleHandler.registerModule("data", new DataModule());
	moduleHandler.registerModule("comfort", new ComfortModule());

	Server server(&updateHandler, &moduleHandler, &dataWorker, &commandWorker, &app);
	server.listen(27015);
    
	return app.exec();
}