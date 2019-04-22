#include <stdio.h>
#include "eurovition.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "map.h"


typedef struct {
    char *stateName;
    char *songName;
}Map CitizenVote* next;

typedef struct {
    char* judgeName;
    int* judgeResults;
} *JudgeData;

typedef struct {
    Map state;
    Map judge;
}*Eurovision;


Map State = mapCreate(copyStateDataElement, copyKeyElement, freeStateDataElement, freeKeyElement, compareKeyElements);
Map Vote =  mapCreate(copyVoteDataElement, copyKeyElement, freeVoteDataElement, freeVoteKeyElement, compareKeyElements);
Map Judge = mapCreate(copyJudgeDataElement, copyKeyElement, freeJudgeDataElement, freeKeyElement, compareKeyElements);

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

int copyVoteDataElement(int Vote){
    return Vote;
}

int CopyKeyElement (int KeyElement){
    return VoteKeyElement;
}

void freeVoteDataElement(int voteDataElement){
    return;
}

void freeKeyElement(int KeyElement){
    return;
}

int compareVoteKeyElements(int KeyElement1,int KeyElement2){
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

JudgeData copyJudgeDataElement(JudgeData judgeDataToCopy){
    JudgeData NewJudgeData = malloc(sizeof(JudgeData));
    if (NewJudgeData == NULL){}
        return MAP_OUT_OF_MEMORY;
    }
    
    NewJudgeData->judgeName = judgeDataToCopy->judgeName;
    NewJudgeData->judgeResults = judgeDataToCopy->judgeResults;
    return NewJudgeData;


void freeJudgeDataElement(){

}


Eurovision eurovisionCreate();

void eurovisionDestroy(Eurovision eurovision);

EurovisionResult eurovisionAddState(Eurovision eurovision, int stateId,
                                    const char *stateName,
                                    const char *songName);

EurovisionResult eurovisionRemoveState(Eurovision eurovision, int stateId);

EurovisionResult eurovisionAddJudge(Eurovision eurovision, int judgeId,
                                    const char *judgeName,
                                    int *judgeResults);

EurovisionResult eurovisionRemoveJudge(Eurovision eurovision, int judgeId);

EurovisionResult eurovisionAddVote(Eurovision eurovision, int stateGiver,
                                   int stateTaker);

EurovisionResult eurovisionRemoveVote(Eurovision eurovision, int stateGiver,
                                      int stateTaker);

List eurovisionRunContest(Eurovision eurovision, int audiencePercent);

List eurovisionRunAudienceFavorite(Eurovision eurovision);

List eurovisionRunGetFriendlyStates(Eurovision eurovision);