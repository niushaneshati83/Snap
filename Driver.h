#ifndef DRIVER_H
#define DRIVER_H
#include "mission.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<malloc.h>
#include<fstream>
#include<algorithm>
using namespace std;
class Driver
{
    private:
    int driver_id=0;
    vector<int> driver_missions_id;
    vector<mission*> driver_missions;
    public:
    Driver(int d_i);
    int get_driver_id();
    int check_driver(vector<Driver*>drivers,int d_i);
    bool check_mission(vector<mission*>missions,int m_i);
    void find_mission(vector<mission*> missions,int m_i);
    bool check_driver_missions(int m_i);
    void set_mission_drivers(vector<mission*> missions, long int m_i);
    void compelete_mission_deiver(long int start_t,long int end_t,long int distance);
    void print_record_ride(long int start_t, long int end_t, long int distance);
    void print_status();

};
#endif