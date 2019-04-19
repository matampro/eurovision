#include <stdio.h>
#include "eurovition.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "E:\Documents\studies\mtm\hw-1\map.h"

typedef state_t {
    int serial_number;
    char* state_name;
    char* song_name;
    long long int count;
} *State;

typedef struct judge_t{
    int serial_number;
    char* judge_name;
    List;
} *Judge;

struct eurovision_t {

};


Eurovision eurovisionCreate();
void eurovisionDestroy(Eurovision urovision);
EurovisionResult eurovisionAddState (Eurovision urovision, int stateId const char* stateName, const char* songName);
EurovisionResult eurovisionAddJudge(Eurovision urovision, int judgeId, const char* judgeName, int *judgeResults);
EurovisionResult eurovisionRemoveState (Eurovision urovision, int stateId);
EurovisionResult eurovisionRemoveJudge(Eurovision eurovision, int judgeId);
EurovisionResult eurovisionAddVote (Eurovision eurovision, int stateGiver, int stateTaker);
EurovisionResult eurovisionRemoveVote (Eurovision eurovision, int stateGiver, int stateTaker);
List eurovisionRunContest (Eurovision eurovision, int audiencePercent);



struct Eurovition_t{

};




int main() {
    eurovisionRunContest(,)
    return 0;
}