/*
 * supplementary_service_type.h
 *
 * 
 */

#ifndef _OpenAPI_supplementary_service_type_H_
#define _OpenAPI_supplementary_service_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "supplementary_service_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_supplementary_service_type_s OpenAPI_supplementary_service_type_t;
typedef struct OpenAPI_supplementary_service_type_s {
} OpenAPI_supplementary_service_type_t;

OpenAPI_supplementary_service_type_t *OpenAPI_supplementary_service_type_create(
);
void OpenAPI_supplementary_service_type_free(OpenAPI_supplementary_service_type_t *supplementary_service_type);
OpenAPI_supplementary_service_type_t *OpenAPI_supplementary_service_type_parseFromJSON(cJSON *supplementary_service_typeJSON);
cJSON *OpenAPI_supplementary_service_type_convertToJSON(OpenAPI_supplementary_service_type_t *supplementary_service_type);
OpenAPI_supplementary_service_type_t *OpenAPI_supplementary_service_type_copy(OpenAPI_supplementary_service_type_t *dst, OpenAPI_supplementary_service_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_supplementary_service_type_H_ */

