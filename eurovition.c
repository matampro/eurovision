#include <stdio.h>
#include "eurovition.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "map.h"


typedef struct {
    char* stateName;
    char* songName;
    Map CitizenVote* next;

typedef struct {
    char* judgeName;
    int* judgeResults;
} *judgeData;

typedef struct {
    Map state;
    Map judge;
}*Eurovision;


Map State = mapCreate(copyStateDataElement, copyStateKeyElement, freeStateDataElement, freeStateKeyElement, compareStateKeyElements);
Map Judge = mapCreate(copyDataElement, copyKeyElement, freeDataElement, freeKeyElement, compareKeyElements);

bool str

stateData copyStateData(StateData dataToCopy){
    stateData stateDataNew = malloc(sizeof(*stateDataNew));
    if(stateDataNew == NULL){
        return NULL;
    } else{
        int strLen = strlen(dataToCopy->stateName);
        char* stateCopyName = malloc(sizeof(strLen+1));
        if(stateName == NULL){
            return NULL;
        }else{
            stateDataNew->stateName = stateCopyName;
        }

    }

               int strLen = strLen(dataToCopy->stateName);
    char* stateName= malloc(sizeof(StateData)


}

StateData copyStateDataElement(StateData DataToCopy){
    StateData = malloc(sizeof(StateData));
    if (StateData == NULL){
        return MAP_OUT_OF_MEMORY;
    }
    StateData ->
}

Eurovision eurovisionCreate(Eurovision eurovision){
    Map mapState = mapCreate(copyMapDataElements copyDataElement,
                              copyMapKeyElements copyKeyElement,
                                freeMapDataElements freeDataElement,
                                 freeMapKeyElements freeKeyElement,
                                  compareMapKeyElements compareKeyElements)
}


void eurovisionDestroy(Eurovision urovision);
EurovisionResult eurovisionAddState (Eurovision urovision, int stateId const char* stateName, const char* songName);
EurovisionResult eurovisionAddJudge(Eurovision urovision, int judgeId, const char* judgeName, int *judgeResults);
EurovisionResult eurovisionRemoveState (Eurovision urovision, int stateId);
EurovisionResult eurovisionRemoveJudge(Eurovision eurovision, int judgeId);
EurovisionResult eurovisionAddVote (Eurovision eurovision, int stateGiver, int stateTaker);
EurovisionResult eurovisionRemoveVote (Eurovision eurovision, int stateGiver, int stateTaker);
List eurovisionRunContest (Eurovision eurovision, int audiencePercent);




int main() {
    eurovisionRunContest(,)
    return 0;
}