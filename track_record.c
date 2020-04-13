#include "track_record.h"

Record* records[MAX_RECORDS];
int _count =0;

int m_is_available(){
    int i;
    for(i=0; i<MAX_RECORDS; i++){
        if(records[i]==NULL)
            return 1;
    }
    return 0;

}

Record* m_search_by_id(char* n){
    int i;
    for(i=0;i<_count;i++){
        if(records[i]!=NULL && strcmp(records[i]->id, n)==0 )
        return records[i];
    }
    return NULL;
}

int m_first_available(){
    int i;
    for(i=0; i<MAX_RECORDS; i++){
        if(records[i]==NULL)
        return i;
    }
    return -1;
}


void m_create(char* id, char* p, char* t, int d, char* k, int time){
    int index = m_first_available();
    records[index] = (Record*)malloc(sizeof(Record));
    Record* q = records[index];
    strcpy(q->id, id);
    strcpy(q->p_name, p);
    strcpy(q->t_name, t);
    q->date = d;
    strcpy(q->k_name, k);
    q->t_record = time;
    _count++;
}

int m_count(){
     return _count;
}

void m_get_all(Record* a[]){
    int i, c=0;
    for(i=0; i<MAX_RECORDS; i++){
        if(records[i]!=NULL){
            a[c]=records[i];
            c++;
        }
    }
}

char* m_to_string(Record* p){
    static char str[100];
    sprintf(str, "[%s] %s / %s / %d / %s / %d", p->id, p->p_name, p->t_name, p->date, p->k_name, p->t_record);
    return str;
}


int m_get_all_by_name(Record* a[], char* n){
    int i, c=0;
    for(i=0; i<_count; i++){
        if(records[i]!=NULL && (strcmp(records[i]->p_name, n)==0)){
            a[c]=records[i];
            c++;
        }
    }
    return c;
}


int m_get_all_by_id(Record* a[], char* n){
    int i, c=0;
    for(i=0; i<_count; i++){
        if(records[i]!=NULL && (strcmp(records[i]->id, n)==0)){
            a[c]=records[i];
            c++;
        }
    }
    return c;
}

void m_init(){
    int i;
    for(i=0;i<MAX_RECORDS; i++){
        if(records[i] != NULL){
            free(records[i]);
        }
        records[i] = NULL;
    }
    _count = 0;

}

char* m_to_string_save(Record* p){
    static char str[200];
    sprintf(str, "%s %s %s %d %s %d",p->id, p->p_name, p->t_name, p->date, p->k_name, p->t_record);
    return str;

}

void m_delete(Record* p){
    int i, index;
    for(i=0;i<_count;i++){
        if(records[i]==p){
            index = i;
            break;
        }
    }
    free(p);
    records[index] = NULL;
    _count--;
}


void m_update(Record* p, char*p_n, char*t_n, int d, char*k, int t){
    strcpy(p->p_name, p_n);
    strcpy(p->t_name, t_n);
    p->date = d;
    strcpy(p->k_name, k);
    p->t_record = t;
}


void m_rank(Record* a[]){
    Record* dummy;
    int i=0, j=0;
    for(i=0;i<_count;i++){
        for(j=0;j<_count -1; j++){
            if(a[j]->t_record < a[j+1]->t_record){
                dummy = a[j];
                a[j] = a[j+1];
                a[j+1] = dummy;
            }
        }
    } 
}


void m_sort(Record* a[]){
    Record* dummy;
    for(int i=0;i<_count;i++){
        for(int j=0;j<_count -1; j++){
            if(strcmp(a[j]->t_name, a[j+1]->t_name)>0){
                dummy = a[j];
                a[j] = a[j+1];
                a[j+1] = dummy;
            }
        }
    } 


}
