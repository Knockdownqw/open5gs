
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vsmf_update_error.h"

OpenAPI_vsmf_update_error_t *OpenAPI_vsmf_update_error_create(
    OpenAPI_ext_problem_details_t *error,
    bool is_pti,
    int pti,
    char *n1sm_cause,
    OpenAPI_ref_to_binary_data_t *n1_sm_info_from_ue,
    OpenAPI_ref_to_binary_data_t *unknown_n1_sm_info,
    OpenAPI_list_t *failed_to_assign_ebi_list,
    OpenAPI_ng_ap_cause_t *ng_ap_cause,
    bool is__5g_mm_cause_value,
    int _5g_mm_cause_value,
    char *recovery_time,
    OpenAPI_n4_information_t *n4_info,
    OpenAPI_n4_information_t *n4_info_ext1,
    OpenAPI_n4_information_t *n4_info_ext2,
    OpenAPI_n4_information_t *n4_info_ext3
)
{
    OpenAPI_vsmf_update_error_t *vsmf_update_error_local_var = ogs_malloc(sizeof(OpenAPI_vsmf_update_error_t));
    ogs_assert(vsmf_update_error_local_var);

    vsmf_update_error_local_var->error = error;
    vsmf_update_error_local_var->is_pti = is_pti;
    vsmf_update_error_local_var->pti = pti;
    vsmf_update_error_local_var->n1sm_cause = n1sm_cause;
    vsmf_update_error_local_var->n1_sm_info_from_ue = n1_sm_info_from_ue;
    vsmf_update_error_local_var->unknown_n1_sm_info = unknown_n1_sm_info;
    vsmf_update_error_local_var->failed_to_assign_ebi_list = failed_to_assign_ebi_list;
    vsmf_update_error_local_var->ng_ap_cause = ng_ap_cause;
    vsmf_update_error_local_var->is__5g_mm_cause_value = is__5g_mm_cause_value;
    vsmf_update_error_local_var->_5g_mm_cause_value = _5g_mm_cause_value;
    vsmf_update_error_local_var->recovery_time = recovery_time;
    vsmf_update_error_local_var->n4_info = n4_info;
    vsmf_update_error_local_var->n4_info_ext1 = n4_info_ext1;
    vsmf_update_error_local_var->n4_info_ext2 = n4_info_ext2;
    vsmf_update_error_local_var->n4_info_ext3 = n4_info_ext3;

    return vsmf_update_error_local_var;
}

void OpenAPI_vsmf_update_error_free(OpenAPI_vsmf_update_error_t *vsmf_update_error)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == vsmf_update_error) {
        return;
    }
    if (vsmf_update_error->error) {
        OpenAPI_ext_problem_details_free(vsmf_update_error->error);
        vsmf_update_error->error = NULL;
    }
    if (vsmf_update_error->n1sm_cause) {
        ogs_free(vsmf_update_error->n1sm_cause);
        vsmf_update_error->n1sm_cause = NULL;
    }
    if (vsmf_update_error->n1_sm_info_from_ue) {
        OpenAPI_ref_to_binary_data_free(vsmf_update_error->n1_sm_info_from_ue);
        vsmf_update_error->n1_sm_info_from_ue = NULL;
    }
    if (vsmf_update_error->unknown_n1_sm_info) {
        OpenAPI_ref_to_binary_data_free(vsmf_update_error->unknown_n1_sm_info);
        vsmf_update_error->unknown_n1_sm_info = NULL;
    }
    if (vsmf_update_error->failed_to_assign_ebi_list) {
        OpenAPI_list_for_each(vsmf_update_error->failed_to_assign_ebi_list, node) {
            OpenAPI_arp_free(node->data);
        }
        OpenAPI_list_free(vsmf_update_error->failed_to_assign_ebi_list);
        vsmf_update_error->failed_to_assign_ebi_list = NULL;
    }
    if (vsmf_update_error->ng_ap_cause) {
        OpenAPI_ng_ap_cause_free(vsmf_update_error->ng_ap_cause);
        vsmf_update_error->ng_ap_cause = NULL;
    }
    if (vsmf_update_error->recovery_time) {
        ogs_free(vsmf_update_error->recovery_time);
        vsmf_update_error->recovery_time = NULL;
    }
    if (vsmf_update_error->n4_info) {
        OpenAPI_n4_information_free(vsmf_update_error->n4_info);
        vsmf_update_error->n4_info = NULL;
    }
    if (vsmf_update_error->n4_info_ext1) {
        OpenAPI_n4_information_free(vsmf_update_error->n4_info_ext1);
        vsmf_update_error->n4_info_ext1 = NULL;
    }
    if (vsmf_update_error->n4_info_ext2) {
        OpenAPI_n4_information_free(vsmf_update_error->n4_info_ext2);
        vsmf_update_error->n4_info_ext2 = NULL;
    }
    if (vsmf_update_error->n4_info_ext3) {
        OpenAPI_n4_information_free(vsmf_update_error->n4_info_ext3);
        vsmf_update_error->n4_info_ext3 = NULL;
    }
    ogs_free(vsmf_update_error);
}

cJSON *OpenAPI_vsmf_update_error_convertToJSON(OpenAPI_vsmf_update_error_t *vsmf_update_error)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (vsmf_update_error == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [VsmfUpdateError]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!vsmf_update_error->error) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [error]");
        return NULL;
    }
    cJSON *error_local_JSON = OpenAPI_ext_problem_details_convertToJSON(vsmf_update_error->error);
    if (error_local_JSON == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [error]");
        goto end;
    }
    cJSON_AddItemToObject(item, "error", error_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [error]");
        goto end;
    }

    if (vsmf_update_error->is_pti) {
    if (cJSON_AddNumberToObject(item, "pti", vsmf_update_error->pti) == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [pti]");
        goto end;
    }
    }

    if (vsmf_update_error->n1sm_cause) {
    if (cJSON_AddStringToObject(item, "n1smCause", vsmf_update_error->n1sm_cause) == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [n1sm_cause]");
        goto end;
    }
    }

    if (vsmf_update_error->n1_sm_info_from_ue) {
    cJSON *n1_sm_info_from_ue_local_JSON = OpenAPI_ref_to_binary_data_convertToJSON(vsmf_update_error->n1_sm_info_from_ue);
    if (n1_sm_info_from_ue_local_JSON == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [n1_sm_info_from_ue]");
        goto end;
    }
    cJSON_AddItemToObject(item, "n1SmInfoFromUe", n1_sm_info_from_ue_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [n1_sm_info_from_ue]");
        goto end;
    }
    }

    if (vsmf_update_error->unknown_n1_sm_info) {
    cJSON *unknown_n1_sm_info_local_JSON = OpenAPI_ref_to_binary_data_convertToJSON(vsmf_update_error->unknown_n1_sm_info);
    if (unknown_n1_sm_info_local_JSON == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [unknown_n1_sm_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "unknownN1SmInfo", unknown_n1_sm_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [unknown_n1_sm_info]");
        goto end;
    }
    }

    if (vsmf_update_error->failed_to_assign_ebi_list) {
    cJSON *failed_to_assign_ebi_listList = cJSON_AddArrayToObject(item, "failedToAssignEbiList");
    if (failed_to_assign_ebi_listList == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [failed_to_assign_ebi_list]");
        goto end;
    }
    OpenAPI_list_for_each(vsmf_update_error->failed_to_assign_ebi_list, node) {
        cJSON *itemLocal = OpenAPI_arp_convertToJSON(node->data);
        if (itemLocal == NULL) {
            ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [failed_to_assign_ebi_list]");
            goto end;
        }
        cJSON_AddItemToArray(failed_to_assign_ebi_listList, itemLocal);
    }
    }

    if (vsmf_update_error->ng_ap_cause) {
    cJSON *ng_ap_cause_local_JSON = OpenAPI_ng_ap_cause_convertToJSON(vsmf_update_error->ng_ap_cause);
    if (ng_ap_cause_local_JSON == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [ng_ap_cause]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ngApCause", ng_ap_cause_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [ng_ap_cause]");
        goto end;
    }
    }

    if (vsmf_update_error->is__5g_mm_cause_value) {
    if (cJSON_AddNumberToObject(item, "5gMmCauseValue", vsmf_update_error->_5g_mm_cause_value) == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [_5g_mm_cause_value]");
        goto end;
    }
    }

    if (vsmf_update_error->recovery_time) {
    if (cJSON_AddStringToObject(item, "recoveryTime", vsmf_update_error->recovery_time) == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [recovery_time]");
        goto end;
    }
    }

    if (vsmf_update_error->n4_info) {
    cJSON *n4_info_local_JSON = OpenAPI_n4_information_convertToJSON(vsmf_update_error->n4_info);
    if (n4_info_local_JSON == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [n4_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "n4Info", n4_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [n4_info]");
        goto end;
    }
    }

    if (vsmf_update_error->n4_info_ext1) {
    cJSON *n4_info_ext1_local_JSON = OpenAPI_n4_information_convertToJSON(vsmf_update_error->n4_info_ext1);
    if (n4_info_ext1_local_JSON == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [n4_info_ext1]");
        goto end;
    }
    cJSON_AddItemToObject(item, "n4InfoExt1", n4_info_ext1_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [n4_info_ext1]");
        goto end;
    }
    }

    if (vsmf_update_error->n4_info_ext2) {
    cJSON *n4_info_ext2_local_JSON = OpenAPI_n4_information_convertToJSON(vsmf_update_error->n4_info_ext2);
    if (n4_info_ext2_local_JSON == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [n4_info_ext2]");
        goto end;
    }
    cJSON_AddItemToObject(item, "n4InfoExt2", n4_info_ext2_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [n4_info_ext2]");
        goto end;
    }
    }

    if (vsmf_update_error->n4_info_ext3) {
    cJSON *n4_info_ext3_local_JSON = OpenAPI_n4_information_convertToJSON(vsmf_update_error->n4_info_ext3);
    if (n4_info_ext3_local_JSON == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [n4_info_ext3]");
        goto end;
    }
    cJSON_AddItemToObject(item, "n4InfoExt3", n4_info_ext3_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed [n4_info_ext3]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_vsmf_update_error_t *OpenAPI_vsmf_update_error_parseFromJSON(cJSON *vsmf_update_errorJSON)
{
    OpenAPI_vsmf_update_error_t *vsmf_update_error_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *error = NULL;
    OpenAPI_ext_problem_details_t *error_local_nonprim = NULL;
    cJSON *pti = NULL;
    cJSON *n1sm_cause = NULL;
    cJSON *n1_sm_info_from_ue = NULL;
    OpenAPI_ref_to_binary_data_t *n1_sm_info_from_ue_local_nonprim = NULL;
    cJSON *unknown_n1_sm_info = NULL;
    OpenAPI_ref_to_binary_data_t *unknown_n1_sm_info_local_nonprim = NULL;
    cJSON *failed_to_assign_ebi_list = NULL;
    OpenAPI_list_t *failed_to_assign_ebi_listList = NULL;
    cJSON *ng_ap_cause = NULL;
    OpenAPI_ng_ap_cause_t *ng_ap_cause_local_nonprim = NULL;
    cJSON *_5g_mm_cause_value = NULL;
    cJSON *recovery_time = NULL;
    cJSON *n4_info = NULL;
    OpenAPI_n4_information_t *n4_info_local_nonprim = NULL;
    cJSON *n4_info_ext1 = NULL;
    OpenAPI_n4_information_t *n4_info_ext1_local_nonprim = NULL;
    cJSON *n4_info_ext2 = NULL;
    OpenAPI_n4_information_t *n4_info_ext2_local_nonprim = NULL;
    cJSON *n4_info_ext3 = NULL;
    OpenAPI_n4_information_t *n4_info_ext3_local_nonprim = NULL;
    error = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "error");
    if (!error) {
        ogs_error("OpenAPI_vsmf_update_error_parseFromJSON() failed [error]");
        goto end;
    }
    error_local_nonprim = OpenAPI_ext_problem_details_parseFromJSON(error);
    if (!error_local_nonprim) {
        ogs_error("OpenAPI_ext_problem_details_parseFromJSON failed [error]");
        goto end;
    }

    pti = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "pti");
    if (pti) {
    if (!cJSON_IsNumber(pti)) {
        ogs_error("OpenAPI_vsmf_update_error_parseFromJSON() failed [pti]");
        goto end;
    }
    }

    n1sm_cause = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "n1smCause");
    if (n1sm_cause) {
    if (!cJSON_IsString(n1sm_cause) && !cJSON_IsNull(n1sm_cause)) {
        ogs_error("OpenAPI_vsmf_update_error_parseFromJSON() failed [n1sm_cause]");
        goto end;
    }
    }

    n1_sm_info_from_ue = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "n1SmInfoFromUe");
    if (n1_sm_info_from_ue) {
    n1_sm_info_from_ue_local_nonprim = OpenAPI_ref_to_binary_data_parseFromJSON(n1_sm_info_from_ue);
    if (!n1_sm_info_from_ue_local_nonprim) {
        ogs_error("OpenAPI_ref_to_binary_data_parseFromJSON failed [n1_sm_info_from_ue]");
        goto end;
    }
    }

    unknown_n1_sm_info = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "unknownN1SmInfo");
    if (unknown_n1_sm_info) {
    unknown_n1_sm_info_local_nonprim = OpenAPI_ref_to_binary_data_parseFromJSON(unknown_n1_sm_info);
    if (!unknown_n1_sm_info_local_nonprim) {
        ogs_error("OpenAPI_ref_to_binary_data_parseFromJSON failed [unknown_n1_sm_info]");
        goto end;
    }
    }

    failed_to_assign_ebi_list = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "failedToAssignEbiList");
    if (failed_to_assign_ebi_list) {
        cJSON *failed_to_assign_ebi_list_local = NULL;
        if (!cJSON_IsArray(failed_to_assign_ebi_list)) {
            ogs_error("OpenAPI_vsmf_update_error_parseFromJSON() failed [failed_to_assign_ebi_list]");
            goto end;
        }

        failed_to_assign_ebi_listList = OpenAPI_list_create();

        cJSON_ArrayForEach(failed_to_assign_ebi_list_local, failed_to_assign_ebi_list) {
            if (!cJSON_IsObject(failed_to_assign_ebi_list_local)) {
                ogs_error("OpenAPI_vsmf_update_error_parseFromJSON() failed [failed_to_assign_ebi_list]");
                goto end;
            }
            OpenAPI_arp_t *failed_to_assign_ebi_listItem = OpenAPI_arp_parseFromJSON(failed_to_assign_ebi_list_local);
            if (!failed_to_assign_ebi_listItem) {
                ogs_error("No failed_to_assign_ebi_listItem");
                goto end;
            }
            OpenAPI_list_add(failed_to_assign_ebi_listList, failed_to_assign_ebi_listItem);
        }
    }

    ng_ap_cause = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "ngApCause");
    if (ng_ap_cause) {
    ng_ap_cause_local_nonprim = OpenAPI_ng_ap_cause_parseFromJSON(ng_ap_cause);
    if (!ng_ap_cause_local_nonprim) {
        ogs_error("OpenAPI_ng_ap_cause_parseFromJSON failed [ng_ap_cause]");
        goto end;
    }
    }

    _5g_mm_cause_value = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "5gMmCauseValue");
    if (_5g_mm_cause_value) {
    if (!cJSON_IsNumber(_5g_mm_cause_value)) {
        ogs_error("OpenAPI_vsmf_update_error_parseFromJSON() failed [_5g_mm_cause_value]");
        goto end;
    }
    }

    recovery_time = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "recoveryTime");
    if (recovery_time) {
    if (!cJSON_IsString(recovery_time) && !cJSON_IsNull(recovery_time)) {
        ogs_error("OpenAPI_vsmf_update_error_parseFromJSON() failed [recovery_time]");
        goto end;
    }
    }

    n4_info = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "n4Info");
    if (n4_info) {
    n4_info_local_nonprim = OpenAPI_n4_information_parseFromJSON(n4_info);
    if (!n4_info_local_nonprim) {
        ogs_error("OpenAPI_n4_information_parseFromJSON failed [n4_info]");
        goto end;
    }
    }

    n4_info_ext1 = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "n4InfoExt1");
    if (n4_info_ext1) {
    n4_info_ext1_local_nonprim = OpenAPI_n4_information_parseFromJSON(n4_info_ext1);
    if (!n4_info_ext1_local_nonprim) {
        ogs_error("OpenAPI_n4_information_parseFromJSON failed [n4_info_ext1]");
        goto end;
    }
    }

    n4_info_ext2 = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "n4InfoExt2");
    if (n4_info_ext2) {
    n4_info_ext2_local_nonprim = OpenAPI_n4_information_parseFromJSON(n4_info_ext2);
    if (!n4_info_ext2_local_nonprim) {
        ogs_error("OpenAPI_n4_information_parseFromJSON failed [n4_info_ext2]");
        goto end;
    }
    }

    n4_info_ext3 = cJSON_GetObjectItemCaseSensitive(vsmf_update_errorJSON, "n4InfoExt3");
    if (n4_info_ext3) {
    n4_info_ext3_local_nonprim = OpenAPI_n4_information_parseFromJSON(n4_info_ext3);
    if (!n4_info_ext3_local_nonprim) {
        ogs_error("OpenAPI_n4_information_parseFromJSON failed [n4_info_ext3]");
        goto end;
    }
    }

    vsmf_update_error_local_var = OpenAPI_vsmf_update_error_create (
        error_local_nonprim,
        pti ? true : false,
        pti ? pti->valuedouble : 0,
        n1sm_cause && !cJSON_IsNull(n1sm_cause) ? ogs_strdup(n1sm_cause->valuestring) : NULL,
        n1_sm_info_from_ue ? n1_sm_info_from_ue_local_nonprim : NULL,
        unknown_n1_sm_info ? unknown_n1_sm_info_local_nonprim : NULL,
        failed_to_assign_ebi_list ? failed_to_assign_ebi_listList : NULL,
        ng_ap_cause ? ng_ap_cause_local_nonprim : NULL,
        _5g_mm_cause_value ? true : false,
        _5g_mm_cause_value ? _5g_mm_cause_value->valuedouble : 0,
        recovery_time && !cJSON_IsNull(recovery_time) ? ogs_strdup(recovery_time->valuestring) : NULL,
        n4_info ? n4_info_local_nonprim : NULL,
        n4_info_ext1 ? n4_info_ext1_local_nonprim : NULL,
        n4_info_ext2 ? n4_info_ext2_local_nonprim : NULL,
        n4_info_ext3 ? n4_info_ext3_local_nonprim : NULL
    );

    return vsmf_update_error_local_var;
end:
    if (error_local_nonprim) {
        OpenAPI_ext_problem_details_free(error_local_nonprim);
        error_local_nonprim = NULL;
    }
    if (n1_sm_info_from_ue_local_nonprim) {
        OpenAPI_ref_to_binary_data_free(n1_sm_info_from_ue_local_nonprim);
        n1_sm_info_from_ue_local_nonprim = NULL;
    }
    if (unknown_n1_sm_info_local_nonprim) {
        OpenAPI_ref_to_binary_data_free(unknown_n1_sm_info_local_nonprim);
        unknown_n1_sm_info_local_nonprim = NULL;
    }
    if (failed_to_assign_ebi_listList) {
        OpenAPI_list_for_each(failed_to_assign_ebi_listList, node) {
            OpenAPI_arp_free(node->data);
        }
        OpenAPI_list_free(failed_to_assign_ebi_listList);
        failed_to_assign_ebi_listList = NULL;
    }
    if (ng_ap_cause_local_nonprim) {
        OpenAPI_ng_ap_cause_free(ng_ap_cause_local_nonprim);
        ng_ap_cause_local_nonprim = NULL;
    }
    if (n4_info_local_nonprim) {
        OpenAPI_n4_information_free(n4_info_local_nonprim);
        n4_info_local_nonprim = NULL;
    }
    if (n4_info_ext1_local_nonprim) {
        OpenAPI_n4_information_free(n4_info_ext1_local_nonprim);
        n4_info_ext1_local_nonprim = NULL;
    }
    if (n4_info_ext2_local_nonprim) {
        OpenAPI_n4_information_free(n4_info_ext2_local_nonprim);
        n4_info_ext2_local_nonprim = NULL;
    }
    if (n4_info_ext3_local_nonprim) {
        OpenAPI_n4_information_free(n4_info_ext3_local_nonprim);
        n4_info_ext3_local_nonprim = NULL;
    }
    return NULL;
}

OpenAPI_vsmf_update_error_t *OpenAPI_vsmf_update_error_copy(OpenAPI_vsmf_update_error_t *dst, OpenAPI_vsmf_update_error_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_vsmf_update_error_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_vsmf_update_error_convertToJSON() failed");
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

    OpenAPI_vsmf_update_error_free(dst);
    dst = OpenAPI_vsmf_update_error_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

