#include <stdio.h>
#include "eurovision.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define NUMBER_OF_RESULTS 10

char* stringCopy(char* str) {
    int strLen =(int) strlen(str);
    char *strDest = malloc(sizeof(strLen + 1));
    if (strDest == NULL) {
        return NULL;
    } else {
        strcpy(strDest, str);
    }
    return strDest;
}


static StateDataMap copyStateData(StateDataMap dataToCopy){
    StateData data =(StateData) dataToCopy;
    StateData stateDataNew = malloc(sizeof(*stateDataNew));
    if(stateDataNew == NULL){
        return NULL;
    } else{
        stateDataNew->stateName = stringCopy(data->stateName);
        if(stateDataNew->stateName == NULL) {
            return NULL;
        }
        stateDataNew->songName = stringCopy(data->songName);
        if(stateDataNew->songName == NULL){
            free(data->stateName);
            return NULL;
        }
        Map citizenVoteDest = mapCopy(data->citizenVote);
        if(citizenVoteDest == NULL){
            free(data->stateName);
            free(data->songName);
            return NULL;
        }
        data->citizenVote = citizenVoteDest;
    }
    return stateDataNew;
}
/** Function to be used by the map for freeing elements */
static void freeStateData(StateDataMap dataToFree) {
    StateData toFree= (StateData) dataToFree;
    free(toFree->stateName);                                   /////(*)?
    free(toFree->songName);
    mapDestroy(toFree->citizenVote);
}


static VoteDataElement copyVoteDataElement(VoteDataElement voteToCopy){
    int *ptr = malloc(sizeof(int));
    if(ptr == NULL){
        return NULL;
    }
    *ptr = *(int*)voteToCopy;
    return ptr;
}

static KeyElement copyKeyElement(KeyElement keyToCopy){
    int *ptr = malloc(sizeof(int));
    if(ptr == NULL){
        return NULL;
    }
    *ptr = *(int*)keyToCopy;
    return ptr;
}

void freeVoteDataElement(VoteDataElement voteToFree){
    free(voteToFree);
}

void freeKeyElement(KeyElement keyToFree){
    free(keyToFree);
}

int compareKeyElements(KeyElement key1,KeyElement key2){
    int a = *(int*)key1;
    int b = *(int*)key2;
    if (a > b){
        return 1;
    }
    else if (a == b) {
        return 0;
    }
    else {
        return -1;
    }
/*
stateData copyStateData(StateData dataToCopy) {
    stateData stateDataNew = malloc(sizeof(*stateDataNew));
    if (stateDataNew == NULL) {
        return NULL;
    } else {
        if (stringCopy(dataToCopy->stateName) == NULL) {
            return NULL;  // need to be fixed. can be NULL later
        } else {
            stateDataNew->stateName = stringCopy(dataToCopy->stateName);
        }
        if (stringCopy(dataToCopy->songName) == NULL) {    // need to be fixed. can be NULL later
            stateDataNew->stateName = stringCopy(dataToCopy->stateName);
            if (stateDataNew->stateName == NULL) {
                return NULL;
            }
            stateDataNew->songName = stringCopy(dataToCopy->songName);
            if (stateDataNew->songName == NULL) {
                free(dataToCopy->stateName)
                return NULL;
            }
            Map citizenVoteDest = mapCopy(dataToCopy->citizenVote);
            if (citizenVoteDest == NULL) {
                free(dataToCopy->stateName);
                free(dataToCopy->songName);
                return NULL;
            }
            dataToCopy->citizenVote = citizenVoteDest;
        }
        return stateDataNew;
    }

    int copyVoteDataElement(int Vote) {
        return Vote;
    }

    int CopyKeyElement(int KeyElement) {
        return VoteKeyElement;
    }

    void freeVoteDataElement(int voteDataElement) {
        return;
    }

    void freeKeyElement(int KeyElement) {
        return;

    }

    int CompareKeyElements(int KeyElement1, int KeyElement2) {
        if (KeyElement1 > KeyElement2) {
            return 1;
        } else if (KeyElement1 == KeyElement2) {
            return 0;
        } else { //the second is bigger
            return -1;
        }
    }

*/
//JudgeData copyJudgeDataElement(JudgeData judgeDataToCopy) {
//    JudgeData NewJudgeData = malloc(sizeof(JudgeData));
//    if (NewJudgeData == NULL)
//        return MAP_OUT_OF_MEMORY;
//
//    char *Name = stringCopy(judgeDataToCopy->judgeName);
//    if (Name == NULL) {
//        return MEMORY_ERROR;
//    }
//    NewJudgeData->judgeName = Name;
//    NewJudgeData->judgeResults = malloc(sizeof(NUMBER_OF_RESULTS));
//    if (New) {
//        return MAP_MEMORY_P
//    }
//    for (i = 0; i < NUMBER_OF_RESULTS; i++) {
//        NewJudgeData->judgeResults[i] = judgeDataToCopy->judgeResults[i];
//    }
//    return NewJudgeData;
//}

//    JudgeData copyJudgeDataElement(JudgeData judgeDataToCopy) {
  //      JudgeData NewJudgeData = malloc(sizeof(*NewJudgeData));
//        if (NewJudgeData == NULL) {
//            return MAP_OUT_OF_MEMORY;
//        }
///    }

/*}
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
*/
Eurovision eurovisionCreate(){
    Eurovision eurovision = malloc(sizeof(*eurovision));
    if(eurovision == NULL){
        return NULL;
    }

    eurovision->state = mapCreate(copyStateData,copyKeyElement,freeStateData,freeKeyElement,compareKeyElements);
    if(eurovision->state == NULL){
        free(eurovision);
        return NULL;
    }
//    eurovision->judge = mapCreate(copyJudgeDataElement,copyKeyElement,freeJudgeDataElement,freeKeyElement,
//                                                                                                compareKeyElements);
    if(eurovision->judge == NULL){
        free(eurovision);
        free(eurovision->state);
        return NULL;
    }
    return eurovision;
}

void eurovisionDestroy(Eurovision eurovision){
    mapDestroy(eurovision->state);
    mapDestroy(eurovision->judge);
}
int main()
{
    Eurovision h= eurovisionCreate();

}

EurovisionResult eurovisionAddState(Eurovision eurovision, int stateId,

                                    const char *stateName,
                                    const char *songName)
{
    StateData  p;

    p->stateName = stateName;
    p->songName = songName;

    mapPut(eurovision->state,&stateId,&p);
}

//Map Vote =  mapCreate(copyVoteDataElement, copyKeyElement, freeVoteDataElement, freeVoteKeyElement, compareKeyElements);
EurovisionResult eurovisionRemoveState(Eurovision eurovision, int stateId);

EurovisionResult eurovisionAddJudge(Eurovision eurovision, int judgeId,
                                    const char *judgeName,
                                    int *judgeResults);

EurovisionResult eurovisionRemoveJudge(Eurovision eurovision, int judgeId);

EurovisionResult eurovisionAddVote(Eurovision eurovision, int stateGiver,
                                   int stateTaker)
{
    StateData stateData = (StateData)mapGet(eurovision->state,&stateGiver);

    secitizenVote  secMap = (citizenVote)mapGet( stateData->citizenVote,&stateTaker);
    
    mapPut(secMap,mapGet(&stateTaker)+1);

}

EurovisionResult eurovisionRemoveVote(Eurovision eurovision, int stateGiver,
                                      int stateTaker);

List eurovisionRunContest(Eurovision eurovision, int audiencePercent);

List eurovisionRunAudienceFavorite(Eurovision eurovision);

List eurovisionRunGetFriendlyStates(Eurovision eurovision);
 */
