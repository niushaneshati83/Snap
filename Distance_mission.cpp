#include "mission.h"
#include "Distance_mission.h"
using namespace std;
Distance_mission:: Distance_mission (int m_i,long int s_ts,long int e_ts,long int t_d_i_m,long int r_a)
    {
        mission_id=m_i;
        start_timestamp=s_ts;
        end_timestmp=e_ts;
        target_distance_in_meters=t_d_i_m;
        reward_amount=r_a;
    }

    bool Distance_mission:: check_target_reward(long int target_distance,long int reward)
    {
        if(target_distance<0 || reward<0)
            return false;
        else
            return true;
    }
    void Distance_mission:: complete_mission(long int start_t,long int end_t,long int distance)
    {
        if(start_timestamp<=start_t && end_t<=end_timestmp)
        {
           target_distance_in_meters=target_distance_in_meters - distance;
        if(target_distance_in_meters<=0)
        {
          status="completed";
          end_time_trip=end_t;
        }
        else
            status="ongoing";
        }
    }

    long int Distance_mission:: get_distance_m()
    {
        return distance_m;
    }