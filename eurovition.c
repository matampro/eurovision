#include <stdio.h>
#include "eurovition.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "map.h"
#define NUMBER_OF_RESULTS 10

typedef struct {
    char *stateName;
    char *songName;
    Map citizenVote* next;
}*stateData;

typedef struct {
    char* judgeName;
    int* judgeResults;
} *JudgeData;

typedef struct {
    Map state;
    Map judge;
}*Eurovision;

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
            return NULL;  // need to be fixed. can be NULL later
        }else{
            stateDataNew->stateName = stringCopy(dataToCopy->stateName);
        }
        if(stringCopy(dataToCopy->songName) == NULL){    // need to be fixed. can be NULL later
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

int CopyKeyElement (int KeyElement){
    return VoteKeyElement;
}

void freeVoteDataElement(int voteDataElement){
    return;
}

void freeKeyElement(int KeyElement){
    return;
}

int CompareKeyElements(int KeyElement1,int KeyElement2){
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
    JudgeData NewJudgeData = malloc(sizeof(*NewJudgeData));
    if (NewJudgeData == NULL)
        return MAP_OUT_OF_MEMORY;
    }
    char* Name = stringCopy(judgeDataToCopy->judgeName);
    if (Name == NULL){
        return  MAP_OUT_OF_MEMORY;
    }
    NewJudgeData->judgeName = Name;
    NewJudgeData->judgeResults = malloc(sizeof(NUMBER_OF_RESULTS));
    if (New){
        return  MAP_OUT_OF_MEMORY
    }
    for(i = 0; i < NUMBER_OF_RESULTS; i++){
        NewJudgeData->judgeResults[i] = judgeDataToCopy->judgeResults[i];
    }
    return NewJudgeData;


void freeJudgeDataElement(JudgeData judgeDataToDelete){
    free(judgeDataToDelete->judgeName);
    free(judgeDataToDelete->judgeResults);
}


Eurovision eurovisionCreate(){
    Map State = mapCreate(copyStateDataElement, copyKeyElement, freeStateDataElement, freeKeyElement, compareKeyElements);
    Map Vote =  mapCreate(copyVoteDataElement, copyKeyElement, freeVoteDataElement, freeVoteKeyElement, compareKeyElements);
    Map Judge = mapCreate(copyJudgeDataElement, copyKeyElement, freeJudgeDataElement, freeKeyElement, compareKeyElements);

};

void eurovisionDestroy(Eurovision eurovision);

EurovisionResult eurovisionAddState(Eurovision eurovision, int stateId,
                                    const char *stateName, const char *songName){
    eurovision->state->key_element

}

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
