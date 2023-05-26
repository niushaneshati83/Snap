#include "Time_mission.h"
#include "mission.h"

using namespace std;
Time_mission::Time_mission(int m_i,long int s_ts,long int e_ts,long int t_t_i_m,long int r_a)
    {
        mission_id=m_i;
        start_timestamp=s_ts;
        end_timestmp=e_ts;
        target_time_in_minutes=t_t_i_m;
        reward_amount=r_a;
    }

    

    bool Time_mission:: check_target_reward(long int target_time,long int reward)
    {
        if(target_time<0 || reward<0)
            return false;
        else
            return true;
    }
    void Time_mission:: set_target(long int target_time_in_minutes)
    {
    target_time_in_seconds=target_time_in_minutes*60;
    }

   void Time_mission:: complete_mission(long int start_t,long int end_t,long int distance)
    {
        
            if(end_t - start_t >= target_time_in_seconds)
            {
              status="completed";
              end_time_trip=end_t;
            }
            else
                status="ongoing";
    }
