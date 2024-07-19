/*
 * tad_identifier_any_of.h
 *
 * 
 */

#ifndef _OpenAPI_tad_identifier_any_of_H_
#define _OpenAPI_tad_identifier_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { OpenAPI_tad_identifier_any_of_NULL = 0, OpenAPI_tad_identifier_any_of_CS, OpenAPI_tad_identifier_any_of_PS } OpenAPI_tad_identifier_any_of_e;

char* OpenAPI_tad_identifier_any_of_ToString(OpenAPI_tad_identifier_any_of_e tad_identifier_any_of);

OpenAPI_tad_identifier_any_of_e OpenAPI_tad_identifier_any_of_FromString(char* tad_identifier_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_tad_identifier_any_of_H_ */

