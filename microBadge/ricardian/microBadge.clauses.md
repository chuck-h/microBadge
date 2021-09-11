<h1 class="clause">Purpose</h1>

This contract supports a lightweight "badging" system whereby any Telos account may issue a named badge (e.g. "permaculture practitioner") to any other account. The two accounts are called the "issuer" and the "badgee", respectively.

The contract itself implements no semantics, although default semantics are described in the ricardian contract. Because two issuers may use the same badge name for different purposes, the meaning of an action should always be interpreted in the context of the issuer identity. The 5 actions supported are
1. init - create a new badge assignment
2. issuerupdate - add information about the badge/badgee (issuer attested)
3. cancel - revoke a badge assignment (issuer action)
4. badgeeupdate - add information about the badge/badgee (badgee attested)
5. badgeereject - signal that the badgee does not accept or agree to the badge 

<h1 class="clause">Issuing Actions</h1>

Example
```
cleos -u https://api.telos.caleos.io push transaction '{
  "delay_sec": 0,
  "max_cpu_usage_ms": 0,
  "actions": [
    {
      "account": "microbadger2",
      "name": "init",
      "data": {
        "issuer": "alinevanmoer",
        "badge": "permaculturist",
        "badgee": "freedomcell1",
        "memo": "{'discordname':'@Miguel_regenerativo'}"
      },
      "authorization": [
        {
          "actor": "alinevanmoer",
          "permission": "active"
        }
      ]
    }
  ]
}'
```

<h1 class="clause">Effect</h1>

This contract leaves only a "journal" of badge events on the blockchain. The contract contains no database which can be queried about badge assignments. (The only table maintained by the contract simply counts the number of badges issued and the number of badging actions.)

<h1 class="clause">Use with history functions</h1>

Most Telos block producing nodes offer a standard history interface which can be queried via http. The history interface offers basic filtering capabilities which are useful with the badging journal created on the blockchain by this contract. For example, 
`https://telos.caleos.io/v2/history/get_actions?account=myissuer&filter=microbadger2%3Ainit&skip=0&limit=100&sort=desc`
will return a JSON-encoded response listing all the badges issued by the myissuer account. For more sophisticated presentation or analysis the response may be handled by server- or client-side code.

Simple history filtering is available in an interactive web UI through most block explorers e.g. `telos.bloks.io`.

This contract leaves only a "journal" of badge events on the blockchain. The contract 
<h1 class="clause">Disclaimer</h1>

This contract is a work in progress and performance is not guaranteed
