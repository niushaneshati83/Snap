#ifndef COUNT_MISSION_H
#define COUNT_MISSION_H
#include "mission.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<malloc.h>
#include<fstream>
#include<algorithm>
using namespace std;
 class Count_mission : public mission
 {
    private:
    int target_number=0;
    int num_of_missions=0;
    public:
    Count_mission(int m_i,long int s_ts=0,long int e_ts=0,long int t_n=0,long int r_a=0);
    bool check_target_reward(long int target_count,long int reward);
    void complete_mission(long int start_t,long int end_t,long int distance);
 };
 #endif