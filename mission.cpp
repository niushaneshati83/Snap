#include "mission.h"
using namespace std;
int mission::get_mission_id()
    {
        return mission_id;
    }

bool mission::check_mission_id(vector<mission*>missions,int mission_id)
    {
        int flag=1;
        for(int i=0;i<missions.size();i++)
        {
            if(missions[i]->get_mission_id()==mission_id)
            {
                flag=0;
            }
        }
        if(flag==1)
            return true;
        else
        
            return false;
        
    }

bool mission::check_time(long int start_time,long int end_time)
    {
        if(end_time<start_time)
            return false;
        else
            return true;
    }


string mission:: get_status()
   {
    return status;
   }

long int mission:: get_start_time()
   {
    return start_timestamp;
   }
   long int mission:: get_end_time_trip()
   {
    return end_time_trip;
   }
   long int mission:: get_reward()
   {
    return reward_amount;
   }