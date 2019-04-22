#include <stdio.h>
#include "eurovition.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "map.h"


typedef struct {
    char *stateName;
    char *songName;
    Map citizenVote* next;
}*stateData;

typedef struct {
    char* judgeName;
    int* judgeResults;
} *judgeData;

typedef struct {
    Map state;
    Map judge;
}*Eurovision;


Map State = mapCreate(copyStateDataElement, copyStateKeyElement, freeStateDataElement, freeStateKeyElement, compareStateKeyElements);
Map Vote =  mapCreate(copyVoteDataElement, copyVoteKeyElement, freeVoteDataElement, freeVoteKeyElement, compareVoteKeyElements);
Map Judge = mapCreate(copyJudgeDataElement, copyJudgeKeyElement, freeJudgeDataElement, freeJudgeKeyElement, compareJudgeKeyElements);

char* stringCopy(char* str) {
    int strLen = strlen(str);
    char *strDest = malloc(sizeof(strLen + 1));
    if (strDest == NULL) {
        return NULL;
    } else {
        strcpy(strDest, str);
    }
    return strDest;
}

stateData copyStateData(StateData dataToCopy){
    stateData stateDataNew = malloc(sizeof(*stateDataNew));
    if(stateDataNew == NULL){
        return NULL;
    } else{
        if(stringCopy(dataToCopy->stateName) == NULL){
            return NULL;
        }else{
            stateDataNew->stateName = stringCopy(dataToCopy->stateName);
        }
        if(stringCopy(dataToCopy->songName) == NULL){
            free(dataToCopy->stateName)
            return NULL;
        }else {
            stateDataNew->songName = stringCopy(dataToCopy->songName);
        }
        Map citizenVote = mapCopy(dataToCopy->citizenVote);
        if
    }


}

int copyVoteDataElement(int Vote){
    return Vote;
}

int CopyVoteKeyElement (int VoteKeyElement){
    return VoteKeyElement;
}

void freeVoteDataElement(VoteKeyElement voteDataElement){
    return;
}

void freeVoteKeyElement(VoteKeyElement voteKeyElement){
    return;
}

int compareVoteKeyElements(VoteKeyElement KeyElement1,VoteKeyElement KeyElement2){
    if (KeyElement1 > KeyElement2){
        return 1;
    }
    else if (KeyElement1 == KeyElement2){
        return 0;
    }
    else{ //the second is bigger
        return -1;
    }
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