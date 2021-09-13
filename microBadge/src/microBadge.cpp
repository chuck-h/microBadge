#include <microBadge.hpp>

void microBadge::increment_calls() {
    auto calls_row = calls.get();
    calls_row.all += 1;
    calls.set(calls_row, _self);
}

[[eosio::action]]
void microBadge::init( name issuer, string badge, name badgee, string memo ) {
    require_auth( issuer );
    check( is_account( badgee ), "badgee account does not exist");
    auto calls_row = calls.get();
    calls_row.inits += 1;
    calls_row.all += 1;
    calls.set(calls_row, _self);
}

[[eosio::action]]
void microBadge::issuerupdate( name issuer, string badge, name badgee, string memo ) {
    require_auth( issuer );
    check( is_account( badgee ), "badgee account does not exist");
    increment_calls();
}

[[eosio::action]]
void microBadge::cancel( name issuer, string badge, name badgee, string memo ) {
    require_auth( issuer );
    check( is_account( badgee ), "badgee account does not exist");
    increment_calls();
}

[[eosio::action]]
void microBadge::badgeeupdate( name issuer, string badge, name badgee, string memo ) {
    require_auth( badgee );
    check( is_account( issuer ), "issuer account does not exist");
    increment_calls();
}

[[eosio::action]]
void microBadge::badgeereject( name issuer, string badge, name badgee, string memo ) {
    require_auth( badgee );
    check( is_account( issuer ), "issuer account does not exist");
    increment_calls();
}


