#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<malloc.h>
#include<fstream>
#include<algorithm>
#include "mission.h"
#include "Driver.h"
#include "Count_mission.h"
#include "Distance_mission.h"
#include "Time_mission.h"

using namespace std;


int main()
{
    vector<mission*> missions;
    vector<Driver*> drivers;

    while(true)
    {
        string order;
        
        cin>>order;
        if(order=="add_time_mission")
        {
            int m_i=0;
            long int s_ts=0,e_ts=0,t_t_i_m=0,r_a=0;
            cin>>m_i>>s_ts>>e_ts>>t_t_i_m>>r_a;
            Time_mission *time_mission = new Time_mission(m_i,s_ts,e_ts,t_t_i_m,r_a);
            if(time_mission->check_mission_id(missions,m_i)==true)
            {
                if(time_mission->check_time(s_ts,e_ts)==true)
                {
                    if(time_mission->check_target_reward(t_t_i_m,r_a)==true)
                    {
                    time_mission->set_target(t_t_i_m);
                    missions.push_back(time_mission);
                    cout<<"OK"<<'\n';
                    }
                    else
                    {
                        cout<<"INVALID_ARGUMENTS"<<'\n';
                    }
                }
                
                else
                {
                    cout<<"INVALID_ARGUMENTS"<<'\n';
                }
            }
            else
            {
                cout<<"DUPLICATE_MISSION_ID"<<'\n';
            }
            
        }
        
        else if(order=="add_distance_mission")
        {
            int m_i=0;
            long int s_ts=0,e_ts=0,t_d_i_m=0,r_a=0;
            cin>>m_i>>s_ts>>e_ts>>t_d_i_m>>r_a;
            Distance_mission *distance_mission = new Distance_mission(m_i,s_ts,e_ts,t_d_i_m,r_a);
            if(distance_mission->check_mission_id(missions,m_i)==true)
            {
                if(distance_mission->check_time(s_ts,e_ts)==true)
                {
                    if(distance_mission->check_target_reward(t_d_i_m,r_a)==true)
                    {
                    missions.push_back(distance_mission);
                    cout<<"OK"<<'\n';
                    }
                    else
                    {
                        cout<<"INVALID_ARGUMENTS"<<'\n';
                    }
                }
                else
                {
                    cout<<"INVALID_ARGUMENTS"<<'\n';
                }
            }
            else
            {
                cout<<"DUPLICATE_MISSION_ID"<<'\n';
            }
        }
        else if(order=="add_count_mission")
        {
            int m_i=0;
            long int s_ts=0,e_ts=0,t_n=0,r_a=0;
            cin>>m_i>>s_ts>>e_ts>>t_n>>r_a;
            Count_mission *count_mission = new Count_mission(m_i,s_ts,e_ts,t_n,r_a);
            if(count_mission->check_mission_id(missions,m_i)==true)
            {
                if(count_mission->check_time(s_ts,e_ts)==true)
                {
                    if(count_mission->check_target_reward(t_n,r_a)==true)
                    {
                    missions.push_back(count_mission);
                    cout<<"OK"<<'\n';
                    }
                    else
                    {
                        cout<<"INVALID_ARGUMENTS"<<'\n';
                    }
                }
                else
                {
                    cout<<"INVALID_ARGUMENTS"<<'\n';
                }

            }
            else
            {
                cout<<"DUPLICATE_MISSION_ID"<<'\n';
            }
        }
        else if(order=="assign_mission")
        {
            int d_i=0,m_i=0;
            cin>>m_i;
            cin>>d_i;

            Driver *driver = new Driver(d_i);
            if(driver->check_driver(drivers,d_i) != -1)
            {
                int index=driver->check_driver(drivers,d_i);
                if(driver->check_mission(missions,m_i)==true)
                {
                    if(drivers[index]->check_driver_missions(m_i)==true)
                    {
                    drivers[index]->find_mission(missions,m_i);
                    drivers[index]->set_mission_drivers( missions,m_i);

                    cout<<"OK"<<'\n';
                    }
                    else
                    {
                        cout<<"DUPLICATE_DRIVER_MISSION"<<'\n';
                    }
                    
                }
                else
                {
                    cout<<"MISSION_NOT_FOUND"<<'\n';
                }
            }
            else
            {
                drivers.push_back(driver);
                if(driver->check_mission(missions,m_i)==true)
                {
                    driver->find_mission(missions,m_i);
                    driver->set_mission_drivers( missions,m_i);
                    cout<<"OK"<<'\n';
                }
                else
                {
                    cout<<"MISSION_NOT_FOUND"<<'\n';
                }
            }
        }
        else if(order=="record_ride")
        {
            long int start_t=0,end_t=0,distance=0;
            int d_i=0;
            cin>>start_t>>end_t>>d_i>>distance;
            if(start_t>end_t)
            {
                cout<<"INVALID_ARGUMENTS"<<'\n';
            }
            
            else
            {
                for(int i=0;i<drivers.size();i++)
                {
                    if(drivers[i]->get_driver_id()==d_i)
                    {
                        drivers[i]->compelete_mission_deiver(start_t,end_t,distance);
                        drivers[i]->print_record_ride(start_t,end_t,distance);
                    }
                }
                
            }
        }

        else if(order=="show_missions_status")
        {
            int d_i=0;
            cin>>d_i;
            for(int i=0;i<drivers.size();i++)
                {
                    if(drivers[i]->get_driver_id()==d_i)
                    {
                        drivers[i]->print_status();
                    }
                    else
                    {
                        cout<<"MISSION_NOT_FOUND"<<'\n';
                    }
                }
            
        }

    }
}

            