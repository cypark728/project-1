#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50      // 저장할 수 있는 트랙 레코드 최대 갯수

typedef struct record{
    char id[20];     //Record끼리 구별하기 위한 변수
    char p_name[20]; //플레이어의 이름
    char t_name[20]; //트랙의 이름
    int date;        //날짜
    char k_name[20]; //카트바디(차종)의 이름
    int t_record;    //트랙 레코드
}Record;

int m_is_available();       // 현재 추가할 수 있는 데이터 공간이 있는가?
Record* m_search_by_id(char* n); //id가 일치하는 특정 트랙 레코드 포인터 찾기
int m_first_available(); //추가할 수 있는 가장 빠른 포인터 배열의 인덱스 값 찾기
void m_create(char* id, char* p, char* t, int d, char* k, int time); //입력받은 데이터로 신규 트랙레코드 생성
int m_count(); //현재 저장된 트랙 레코드의 갯수 가져오기
void m_get_all(Record* a[]); //트랙레코드가 들어있는 모든 레코드 포인터의 배열을 만들기
char* m_to_string(Record* p); // 특정 트랙 레코드의 내용을 문자열로 가져오기
int m_get_all_by_name(Record* a[], char* n);  // 트랙 레코드의 이름 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
int m_get_all_by_id(Record* a[], char* n);  // 트랙 레코드의 아이디 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
void m_init(); // 모든 트랙레코드 삭제
char* m_to_string_save(Record* p);// 특정 트랙 레코드의 내용을 파일저장용 문자열로 가져오기
void m_delete(Record* p); //특정 트랙 레코드의 정보 제거
void m_update(Record* p, char*p_n, char*t_n, int d, char*k, int t); // 특정 트랙 레코드의 정보를 업데이트
void m_sort(Record* a[]);// 트랙 레코드를 시간 기록 기준으로 정렬함
int m_rank(Record* a[],char* t);// 트랙 레코드를 트랙 기준으로 정렬함

