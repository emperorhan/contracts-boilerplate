#pragma once

#define CORE_SYM_NAME "LED"
#define CORE_SYM_PRECISION 4

#define PROJECT_SYM_NAME "PROJECT"
#define PROJECT_SYM_PRECISION 4

#define _STRINGIZE1(x) #x
#define _STRINGIZE2(x) _STRINGIZE1(x)

#define CORE_SYM_STR (_STRINGIZE2(CORE_SYM_PRECISION) "," CORE_SYM_NAME)
#define CORE_SYM (::eosio::chain::string_to_symbol_c(CORE_SYM_PRECISION, CORE_SYM_NAME))
#define PROJECT_SYM (::eosio::chain::string_to_symbol_c(PROJECT_SYM_PRECISION, PROJECT_SYM_NAME))

struct core_sym {
    static inline eosio::chain::asset from_string(const std::string& s) {
        return eosio::chain::asset::from_string(s + " " CORE_SYM_NAME);
    }
};

struct project_sym {
    static inline eosio::chain::asset from_string(const std::string& s) {
        return eosio::chain::asset::from_string(s + " " PROJECT_SYM_NAME);
    }
};