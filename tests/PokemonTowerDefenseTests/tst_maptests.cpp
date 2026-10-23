#include <QTest>
#include <QDebug>
#include <QPointF>

#include "../../Map.h"

class MapTests : public QObject
{
    Q_OBJECT

public:
    MapTests();
    ~MapTests() override;

private slots:
    void initTestCase();
    void init();
    void cleanupTestCase();
    void cleanup();
    void testConversionIsometric();
    void testConversionIsometric2();
};

MapTests::MapTests() {}

MapTests::~MapTests() = default;

void MapTests::initTestCase()
{
    // code to be executed before the first test function
}

void MapTests::init()
{
    // code to be executed before each test function
}

void MapTests::cleanupTestCase()
{
    // code to be executed after the last test function
}

void MapTests::cleanup()
{
    // code to be executed after each test function
}

void MapTests::testConversionIsometric()
{
    Map map;
    QSize size(800, 600);

    QPointF result = map.conversionIsometric(0, 0, size);

    QCOMPARE(result.x(), 400.0);
    QCOMPARE(result.y(), 156.0);
    //qDebug() << "Position obtenue : " << result;
}

void MapTests::testConversionIsometric2()
{
    Map map;
    QSize size(800, 600);

    QPointF result = map.conversionIsometric(9, 9, size);

    QCOMPARE(result.x(), 400.0);
    QCOMPARE(result.y(), 444.0);
    //qDebug() << "Position obtenue : " << result;
}

QTEST_APPLESS_MAIN(MapTests)

#include "tst_maptests.moc"
