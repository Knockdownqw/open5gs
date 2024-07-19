#ifndef sm_message_type_any_of_TEST
#define sm_message_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sm_message_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sm_message_type_any_of.h"
sm_message_type_any_of_t* instantiate_sm_message_type_any_of(int include_optional);



sm_message_type_any_of_t* instantiate_sm_message_type_any_of(int include_optional) {
  sm_message_type_any_of_t* sm_message_type_any_of = NULL;
  if (include_optional) {
    sm_message_type_any_of = sm_message_type_any_of_create(
    );
  } else {
    sm_message_type_any_of = sm_message_type_any_of_create(
    );
  }

  return sm_message_type_any_of;
}


#ifdef sm_message_type_any_of_MAIN

void test_sm_message_type_any_of(int include_optional) {
    sm_message_type_any_of_t* sm_message_type_any_of_1 = instantiate_sm_message_type_any_of(include_optional);

	cJSON* jsonsm_message_type_any_of_1 = sm_message_type_any_of_convertToJSON(sm_message_type_any_of_1);
	printf("sm_message_type_any_of :\n%s\n", cJSON_Print(jsonsm_message_type_any_of_1));
	sm_message_type_any_of_t* sm_message_type_any_of_2 = sm_message_type_any_of_parseFromJSON(jsonsm_message_type_any_of_1);
	cJSON* jsonsm_message_type_any_of_2 = sm_message_type_any_of_convertToJSON(sm_message_type_any_of_2);
	printf("repeating sm_message_type_any_of:\n%s\n", cJSON_Print(jsonsm_message_type_any_of_2));
}

int main() {
  test_sm_message_type_any_of(1);
  test_sm_message_type_any_of(0);

  printf("Hello world \n");
  return 0;
}

#endif // sm_message_type_any_of_MAIN
#endif // sm_message_type_any_of_TEST
