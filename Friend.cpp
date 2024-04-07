#include <iostream>

// 全局函数友元
namespace sp1
{
    class Building
    {
        std::string m_SittingRoom;

    public:
        std::string m_BedRoom;
        Building(std::string sittingRoom, std::string bedRoom) : m_SittingRoom(sittingRoom), m_BedRoom(bedRoom) {}
        friend void lightweight(Building &building);
    };
    void lightweight(Building &building)
    {
        std::cout << "global function ======== pub " << building.m_SittingRoom << std::endl;
        std::cout << "global function ======== pri " << building.m_BedRoom << std::endl;
    }
}
// 友元类
namespace sp2
{
    class Building
    {

        std::string m_BedRoom;

    public:
        std::string m_SittingRoom;
        Building(std::string sittingRoom, std::string bedRoom) : m_SittingRoom(sittingRoom), m_BedRoom(bedRoom) {}
        friend class lightweight;
    };
    class lightweight
    {
    public:
        void func(Building &building)
        {
            std::cout << "class function ======== pub " << building.m_SittingRoom << std::endl;
            std::cout << "class function ======== pri " << building.m_BedRoom << std::endl;
        }
    };
}
// 成员函数友元
namespace sp3
{
    class Building;
    class Lightweight
    {
        Building *m_buiding; // m_building的大小未知，使用指针代替
    public:
        Lightweight();
        void visit();
        ~Lightweight();
    };

    class Building
    {
        friend void Lightweight::visit();
        std::string m_BedRoom;

    public:
        std::string SettingRoom;
        Building(std::string settingRoom, std::string bedRoom) : SettingRoom(settingRoom), m_BedRoom(bedRoom) {}
    };

    Lightweight::Lightweight()
    {
        m_buiding = new Building("客厅", "卧室");
        std::cout << "class function ======= pub " << m_buiding->SettingRoom << std::endl;
        // std::cout<<"class function ======= pri "<<m_buiding->m_BedRoom<<std::endl;
    }
    void Lightweight::visit()
    { // Building 只声明visit()函数为友元函数
        std::cout << "class function ======= pub " << m_buiding->SettingRoom << std::endl;
        std::cout << "class function ======= pri " << m_buiding->m_BedRoom << std::endl;
    }
    Lightweight::~Lightweight()
    {
        delete m_buiding;
        m_buiding = nullptr;
    }
}
signed main()
{
    {
        using namespace sp1;
        Building building("客厅", "卧室");
        lightweight(building);
        std::cout << '\n';
    }
    {
        using namespace sp2;
        Building building("客厅", "卧室");
        lightweight lw;
        lw.func(building);
        std::cout << '\n';
    }
    {
        using namespace sp3;
        Lightweight lw;
        std::cout << '\n';
        lw.visit();
    }
}