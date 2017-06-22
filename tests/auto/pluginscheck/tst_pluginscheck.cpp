#include <QtTest>
#include <QTemporaryFile>

// add necessary includes here

#include <pythonPlugins/actuators/pythonpluginabstractfactory.h>
#include <pythonPlugins/environment/PluginFileLoader.h>
#include <pythonPlugins/environment/PythonEnvironment.h>

class pluginsCheck : public QObject
{
    Q_OBJECT

public:
    pluginsCheck();
    ~pluginsCheck();

private slots:
    void test_case1();

};

pluginsCheck::pluginsCheck()
{

}

pluginsCheck::~pluginsCheck()
{

}

void pluginsCheck::test_case1()
{
    QTemporaryFile outFile;
    QTemporaryFile dataFile;

    if (outFile.open() && dataFile.open()) {

        std::shared_ptr<FileSender> com = std::make_shared<FileSender>(outFile.fileName().toStdString(),
                                                                       dataFile.fileName().toStdString());
        try {
            com->connect();

            PluginFileLoader::setPluginDir("X:/pythonPlugins/pythonPluginsTest/tests/auto/pluginscheck/plugins");
            PythonEnvironment::GetInstance()->initEnvironment("X:/pluginScripts/interfacePlugins");

            PythonPluginAbstractFactory factory(com);

            std::shared_ptr<PluginConfiguration> config =
                    std::make_shared<PluginConfiguration>("TestCentrifugator", "Centrifugator", std::unordered_map<std::string,std::string>());
            std::shared_ptr<CentrifugatePluginProduct> centrifugation = factory.makeCentrifugate(config);

            centrifugation->startCentrifugate(100 * units::Hz);

            com->disconnect();

            QTextStream in(&outFile);
            while (!in.atEnd()) {
                std::string expected = "START CENTRIFUGATE100.0";
                std::string generated = in.readLine().toStdString();

                qDebug() << "expected: " << expected.c_str();
                qDebug() << "generated: " << generated.c_str();

                QVERIFY2(expected.compare(generated) == 0, "OUTPUT not as expected look at debug for more info");
            }
        } catch (std::exception & e) {
            PythonEnvironment::GetInstance()->finishEnvironment();
            com->disconnect();

            qDebug() << e.what();
        }
    } else {
        QFAIL("imposible to open temporary files");
    }
}

QTEST_APPLESS_MAIN(pluginsCheck)

#include "tst_pluginscheck.moc"
