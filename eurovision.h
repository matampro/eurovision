#ifndef EUROVISION_H_
#define EUROVISION_H_

#include "list.h"
/**
* Eurovition management program
*

*
* The following functions are available:
*   eurovisionCreate        - Creates a new empty Eurovition
*   EurovitionDestroy       - Deletes an existing Eurovition and frees all resources
*   eurovisionAddState	    - Adds a new state to the management program
*   eurovisionAddJudge  	- Adds a new judge to the management program
*   mapContains	            - returns weather or not a key exists inside the map
*   eurovisionRemoveState   - removes a state from the management program
*   eurovisionRemoveJudge   - removes a judge and his votes from the management program
*   eurovisionAddVote	    - adds a vote from a civilian in country x yo country y
*   eurovisionRemoveVote	- removes a vote from a civilian in country x yo country y
*   eurovisionRunContest    - Runs the contest and returns the list of winners
*/


typedef enum eurovisionResult_t {
    EUROVISION_NULL_ARGUMENT,
    EUROVISION_OUT_OF_MEMORY,
    EUROVISION_INVALID_ID,
    EUROVISION_INVALID_NAME,
    EUROVISION_STATE_ALREADY_EXIST,
    EUROVISION_STATE_NOT_EXIST,
    EUROVISION_JUDGE_ALREADY_EXIST,
    EUROVISION_JUDGE_NOT_EXIST,
    EUROVISION_SAME_STATE,
    EUROVISION_SUCCESS
} EurovisionResult;


typedef struct eurovision_t *Eurovision;

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


#endif /* EUROVISION_H_ */
