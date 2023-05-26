#include "Count_mission.h"
using namespace std;
Count_mission:: Count_mission(int m_i,long int s_ts,long int e_ts,long int t_n,long int r_a)
    {
        mission_id=m_i;
        start_timestamp=s_ts;
        end_timestmp=e_ts;
        target_number=t_n;
        reward_amount=r_a;
    }
    bool Count_mission:: check_target_reward(long int target_count,long int reward)
    {
        if(target_count<0 || reward<0)
            return false;
        else
            return true;
    }
    void Count_mission:: complete_mission(long int start_t,long int end_t,long int distance)
    {
        if(start_timestamp<=start_t && end_t<=end_timestmp)
        {
            num_of_missions++;
        }
        if(num_of_missions>=target_number)
        {
            status="completed";
            end_time_trip=end_t;
        }
        else
            status="ongoing";
    }