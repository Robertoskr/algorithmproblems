//weighted interval scheduling problem using dp
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef schedule

struct schedule{
    int start;
    int finish;
    int value;
};

#endif
int _bestSchedule(vector<schedule> *schedules, int startPoint, int **parents){
    if(parents[startPoint][1] != -1)
        return parents[startPoint][1];
    int max = 0; 
    int actual;
    int selfValue = schedules->at(startPoint).value;
    for(int i = 0; i < schedules->size(); i++){
        if(i != startPoint){
            if(schedules->at(i).start > schedules->at(startPoint).finish){
                actual = _bestSchedule(schedules, i, parents) + selfValue;
                if(actual > max){
                    max = actual;
                    parents[startPoint][0] = i;
                    parents[startPoint][1] = actual;
                }
            }
        }
    }
    if(parents[startPoint][0] == -1){
        parents[startPoint][1] = schedules->at(startPoint).value;
    }
    return parents[startPoint][1];
}

int** bestSchedule(vector<schedule> schedules){
    int size = schedules.size();
    int **parents = new int*[size];
    for(int i = 0; i < size; i++)
        parents[i] = new int[2]{-1, -1};
    int actual;
    int best = 0;
    int bestcost = 0;
    for(int i = 0; i < size; i++){
        actual = _bestSchedule(&schedules, i, parents);
        if(actual > bestcost){
            best = i;
            bestcost = actual;
        }
    }
    cout << " the best is " << best << " with " << bestcost << endl;
    return parents;
}


int main(){
    vector<schedule> schedules{
        schedule{0, 5, 10},
        schedule{1, 3, 12},
        schedule{2, 6, 20},
        schedule{3, 4, 10},
        schedule{5, 7, 2},
        schedule{6, 8, 3},
    };
    int **result = bestSchedule(schedules);
    for(int i = 0 ; i < schedules.size(); i++){
        cout << result[i][0] << " value of " << result[i][1] << endl;
    }
}