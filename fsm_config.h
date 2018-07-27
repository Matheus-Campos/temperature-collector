#define NUM_STATES 6
#define NUM_EVENTS 2

// definicao dos possiveis eventos gerados pelos estados da FSM
typedef enum event_ {empty, action} event;
// definicao das funcoes que implementam o comportamento de cada estado
event idle_state(void);
event connect_state(void);
event send_data_state(void);
event send_data_button_state(void);
event no_connection_state(void);
event end_state(void);
// array de ponteiros para as funcoes dos estados
event (* state_functions[])(void) = {idle_state, connect_state, send_data_state, send_data_button_state, no_connection_state, end_state};
// definicao dos nomes dos estados
typedef enum state_ {idle, connect, send_data, send_data_button, no_connection, end} state;
// estrutura que define as transicoes dos estados
state state_transitions[NUM_STATES][NUM_EVENTS] = {{send_data, send_data_button},
                                                   {idle, connect},
                                                   {idle, no_connection},
                                                   {idle, no_connection},
                                                   {connect, connect},
                                                   {no_connection, no_connection}};
// definicao dos estados inicial e final
#define EXIT_STATE end
#define ENTRY_STATE connect

// funcao que implementa a ransicao de estados
state lookup_transitions(state cur_state, event cur_evt) {
  return state_transitions[cur_state][cur_evt];
}

