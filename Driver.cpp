#include "Driver.h"
using namespace std;
Driver:: Driver(int d_i)
    {
        driver_id=d_i;
    }
    int Driver:: get_driver_id()
    {
        return driver_id;
    }
    int Driver::check_driver(vector<Driver*>drivers,int d_i)
    {
        int flag=-1;
        for(int i=0;i<drivers.size();i++)
        {
            if(drivers[i]->driver_id==d_i)
            {
                flag=i;
            }
           
        }
        return flag;

    }
    bool Driver::check_mission(vector<mission*>missions,int m_i)
    {
        int flag=0;
        for(int i=0;i<missions.size();i++)
        {
            if(missions[i]->get_mission_id()==m_i)
            {
                flag=1;
            }
        }
        if(flag==1)
            return true;
        else
            return false;
    }
    void Driver::find_mission(vector<mission*> missions,int m_i)
    {
        for(int i=0;i<missions.size();i++)
        {
            if(missions[i]->get_mission_id()==m_i)
            {
                driver_missions_id.push_back(m_i);
                
            }
        }
    }
    bool Driver::check_driver_missions(int m_i)
    {
        int flag=0;
        for(int i=0;i<driver_missions_id.size();i++)
        {
            if(driver_missions_id[i]==m_i)
            {
                flag=1;
            }
        }
        if(flag==1)
            return false;
        else    
            return true;
    }
    
    void Driver::set_mission_drivers(vector<mission*> missions, long int m_i)
    {
        for(int i=0;i<missions.size();i++)
        {
            
                if(missions[i]->get_mission_id()==m_i)
                {
                    driver_missions.push_back(missions[i]);
                }
        
        }
    }
    
    void Driver::compelete_mission_deiver(long int start_t,long int end_t,long int distance)
    {
        for(int i=0;i<driver_missions.size();i++)
        {
            driver_missions[i]->complete_mission(start_t,end_t,distance);
        }
    }
    void Driver::print_record_ride(long int start_t, long int end_t, long int distance)
    {
        cout<<"completed missions for driver"<<driver_id<<":"<<'\n';
        for(int i=0;i<driver_missions.size();i++)
        {
            if(driver_missions[i]->get_status()=="completed")
            {
                cout<<"mission"<<driver_missions_id[i]<<" :"<<'\n';
                cout<<"start timestamp: "<<driver_missions[i]->get_start_time()<<'\n';
                cout<<"end timestamp: "<<end_t<<'\n';
                cout<<"reward: "<<driver_missions[i]->get_reward()<<'\n';
            }
        }
    }
    void Driver::print_status()
    {
        
        cout<<"missions status for driver"<<driver_id<<":"<<'\n';
        for(int i=0;i<driver_missions.size();i++)
        {
            cout<<"mission "<<driver_missions[i]->get_mission_id()<<":"<<'\n';
            cout<<"start timestamp:"<<driver_missions[i]->get_start_time()<<'\n';
            if(driver_missions[i]->get_status()=="completed")
            {
                cout<<"end timestamp:"<<driver_missions[i]->get_end_time_trip()<<'\n';
            }
            else
            {
                cout<<"end timestamp: -1"<<'\n';
            }
            cout<<"reward: "<<driver_missions[i]->get_reward()<<'\n';
            cout<<"status: "<<driver_missions[i]->get_status()<<'\n'<<'\n';
            
        }
        

    }