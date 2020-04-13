#include "track_record.h"
#define DEBUG

void create_record();
void read_record();
void update_record();
void delete_record();
void search_id();
void search_name();
void rank_track();
void sort_record();
void load_file();
void save_file();

int main(){
    int menu;
	printf("something fixed");
    while(1){
        printf("\nMenu : 1.Create 2.Read 3.Update 4.Delete 5.Search 6.Search(name) 7.Rank 8.Sort 9.Load 10.Save 0.Exit > ");
        scanf("%d",&menu);
        printf("\n");
        switch(menu){
            case 1: 
                create_record();
                break;
            case 2: 
                read_record();
                break;
            case 3: 
                update_record();
                break;
            case 4: 
                delete_record();
                break;
            case 5: 
                search_id();
                break;
            case 6: 
                search_name();
                break;
            case 7: 
                rank_track();
                break;
            case 8: 
                sort_record();
                break;
            case 9: 
                load_file();
                break;
            case 10: 
                save_file();
                break;
            case 0: 
            default: 
                return 0;
        }
    }
}

void create_record(){
    #ifdef DEBUG
            printf("[DEBUG] create_record is loading.\n");
        #endif
    if(!m_is_available()) {
        printf("There is no space!\n");
        return;
    }
    char id[20], p_name[20], t_name[20], k_name[20];
    int date=0, t_record=0;
    printf("Enter a new member's info.\n");
    printf("Id > ");
    scanf("%s", id);
    if(m_search_by_id(id)) {
        printf("Duplicated id!\n");
        return;
    }
    printf("Player name > ");
    scanf("%s", p_name);
    printf("Track name > ");
    scanf("%s", t_name);
    printf("Date > ");
    scanf("%d", &date);
    printf("Kartbody name > ");
    scanf("%s", k_name);
    printf("Track record > ");  //1분 32초 99 의 경우 13299로 입력받는다
    scanf("%d", &t_record);
    m_create(id, p_name, t_name, date, k_name, t_record);
    #ifdef DEBUG
            printf("[DEBUG] id %s\n", id);
        #endif
}

void read_record(){
    #ifdef DEBUG
            printf("[DEBUG] read_record is loading.\n");
        #endif
    printf("All records.\n");
    int size = m_count();
    Record* records[MAX_RECORDS];
    m_get_all(records);
    for(int i=0;i<size;i++){
        Record* p = records[i];
        printf("%d. %s\n",i+1, m_to_string(p));
        
    }
}

void search_id(){
    #ifdef DEBUG
            printf("[DEBUG] search_id is loading\n");
        #endif
    char id[20];
    printf("Enter a id > ");
    scanf("%s", id);
    #ifdef DEBUG
        printf("[DEBUG] id %s\n", id);
    #endif
    Record* records[MAX_RECORDS];
    int size = m_get_all_by_id(records, id);
    printf("%d records found.\n", size);
    for(int i=0; i<size; i++){
        Record* p = records[i];
        printf("%d. %s\n", i+1, m_to_string(p));
    }
}

void search_name(){
    #ifdef DEBUG
            printf("[DEBUG] search_name is loading\n");
        #endif
    char name[20];
    printf("Enter a name > ");
    scanf("%s", name);
    #ifdef DEBUG
            printf("[DEBUG] name %s\n", name);
        #endif
    Record* records[MAX_RECORDS];
    int size = m_get_all_by_name(records, name);
    printf("%d records found.\n", size);
    for(int i=0; i<size; i++){
        Record* p = records[i];
        printf("%d. %s\n", i+1, m_to_string(p));
    }
}

void update_record(){
    char id[20], p_name[20], t_name[20], k_name[20];
    int date, t_record;
    printf("Enter a id > ");
    scanf("%s", id);

    Record* p = m_search_by_id(id);
    if(p){
        printf("Enter a updated info. \n");
        printf("Player name > ");
        scanf("%s", p_name);
        printf("Track name > ");
        scanf("%s", t_name);
        printf("Date > ");
        scanf("%d", &date);
        printf("kartbody name > ");
        scanf("%s", k_name);
        printf("Track record > ");
        scanf("%d", &t_record);

        m_update(p, p_name, t_name, date, k_name, t_record);
    }else{

        printf("No such member.\n");
    }
}
void delete_record(){
    char id[20];
    printf("Enter a id >");
    scanf("%s", id);

    Record* p = m_search_by_id(id);
    if(p){
        m_delete(p);
        printf("The record is deleted.\n");
    }else {
        printf("No such member!\n");
    }

}
void rank_track(){
    Record* records[MAX_RECORDS];
    int size = m_count();
    printf("The ranking. \n");
    m_get_all(records);
    m_rank(records);

    printf("%d\n", size);
    

    for(int i=0; i<size; i++){
        Record* p = records[i];
        printf("%d. %s\n", i+1, m_to_string(p));
    }
}
void sort_record(){
    Record* records[MAX_RECORDS];
    int size = m_count();
    printf("All record are sorted.\n");
    m_get_all(records);
    m_sort(records);
    

    for(int i=0; i<size; i++){
        Record* p = records[i];
        printf("%d. %s\n", i+1, m_to_string(p));
    }
}
void load_file(){
    #ifdef DEBUG
        printf("[DEBUG] load_file is loading.\n");
    #endif
    int check;
    printf("All data will be deleted and new records will be reloaded.\n");
    printf("1.yes 0.no > ");
    scanf("%d",&check);
    if(check == 0){
        return;
    }
    m_init();

    FILE* f = fopen("track_record.txt", "r");
    char id[20], p_name[20], t_name[20], k_name[20];
    int date=0, t_record=0;
    while(!feof(f)){
        if(!m_is_available()){
            printf("[Load] There is no space!\n");
            break;
        }
        int n = fscanf(f,"%s %s %s %d %s %d",id,p_name,t_name, &date, k_name, &t_record);
        if (n<6) break;

        #ifdef DEBUG
            printf("[DEBUG] %d\n", n);
        #endif

        if(m_search_by_id(id)){
            printf("[Load] Duplicatd id(%s)! loading.\n",id);
            continue;
        }

        m_create(id, p_name, t_name, date, k_name, t_record);
        #ifdef DEBUG
            printf("[DEBUG] load %s\n", id);
        #endif
    }
    printf("%d records are read from file!\n", m_count());
    fclose(f);

}

void save_file(){
    #ifdef DEBUG
        printf("[DEBUG] save_file is loading\n");
    #endif
    FILE* f = fopen("track_record.txt", "w");
    printf("All records. \n");
    int size = m_count();
    Record* records[MAX_RECORDS];
    m_get_all(records);
    for(int i=0;i<size;i++){
        Record* p = records[i];
        fprintf(f, "%s\n", m_to_string_save(p));
    }
    fclose(f);
}

