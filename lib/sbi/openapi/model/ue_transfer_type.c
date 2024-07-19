
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_transfer_type.h"

OpenAPI_ue_transfer_type_t *OpenAPI_ue_transfer_type_create(
)
{
    OpenAPI_ue_transfer_type_t *ue_transfer_type_local_var = ogs_malloc(sizeof(OpenAPI_ue_transfer_type_t));
    ogs_assert(ue_transfer_type_local_var);


    return ue_transfer_type_local_var;
}

void OpenAPI_ue_transfer_type_free(OpenAPI_ue_transfer_type_t *ue_transfer_type)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == ue_transfer_type) {
        return;
    }
    ogs_free(ue_transfer_type);
}

cJSON *OpenAPI_ue_transfer_type_convertToJSON(OpenAPI_ue_transfer_type_t *ue_transfer_type)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (ue_transfer_type == NULL) {
        ogs_error("OpenAPI_ue_transfer_type_convertToJSON() failed [UETransferType]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_ue_transfer_type_t *OpenAPI_ue_transfer_type_parseFromJSON(cJSON *ue_transfer_typeJSON)
{
    OpenAPI_ue_transfer_type_t *ue_transfer_type_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    ue_transfer_type_local_var = OpenAPI_ue_transfer_type_create (
    );

    return ue_transfer_type_local_var;
end:
    return NULL;
}

OpenAPI_ue_transfer_type_t *OpenAPI_ue_transfer_type_copy(OpenAPI_ue_transfer_type_t *dst, OpenAPI_ue_transfer_type_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_ue_transfer_type_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_ue_transfer_type_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        ogs_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        ogs_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_ue_transfer_type_free(dst);
    dst = OpenAPI_ue_transfer_type_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

