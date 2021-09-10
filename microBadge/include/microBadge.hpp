#include <eosio/eosio.hpp>
#include <eosio/singleton.hpp>
using namespace eosio;
using std::string;

class [[eosio::contract]] microBadge : public contract {
   public:
      using contract::contract;
      microBadge(name receiver, name code, datastream<const char *> ds) :
         contract(receiver, code, ds),
         calls(_self, _self.value) {
            if (!calls.exists()) {
               calls.set(CallsStruct{0, 0}, _self);
            }
         }

      [[eosio::action]]
      void init( name issuer, string badge, name badgee, string memo );

      [[eosio::action]]
      void issuerupdate( name issuer, string badge, name badgee, string memo );

      [[eosio::action]]
      void cancel( name issuer, string badge, name badgee, string memo );

      [[eosio::action]]
      void badgeeupdate( name issuer, string badge, name badgee, string memo );

      [[eosio::action]]
      void badgeereject( name issuer, string badge, name badgee, string memo );


      using init_action = eosio::action_wrapper<"init"_n, &microBadge::init>;
      using issuer_update_action = eosio::action_wrapper<"issuerupdate"_n, &microBadge::issuerupdate>;
      using cancel_action = eosio::action_wrapper<"cancel"_n, &microBadge::cancel>;
      using badgee_update_action = eosio::action_wrapper<"badgeeupdate"_n, &microBadge::badgeeupdate>;
      using badgee_reject_action = eosio::action_wrapper<"badgeereject"_n, &microBadge::badgeereject>;
   private:
      void increment_calls();
      struct [[eosio::table]] CallsStruct {
         uint32_t inits;
         uint32_t all;
      };
      typedef singleton<"calls"_n, CallsStruct> calls_table;
      typedef eosio::multi_index<"calls"_n, CallsStruct> dump_for_inits;
      calls_table calls;
};
