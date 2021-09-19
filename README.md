# microBadge

See https://github.com/chuck-h/microBadge/blob/main/microBadge/ricardian/microBadge.clauses.md

In this example contract call, account `agrauthority` gives `farmerthomas` the `permaculturist` badge. (`badgemaster1` is the account holding the microbadge contract; it is shared among all users of the badging service.)
```
{
  "actions":[
    {
      "account":"badgemaster1",
      "name":"init",
      "authorization":[
        {
          "actor":"...........1",
          "permission":"active"
        }
      ],
      "data":{
        "issuer":"agrauthority",
        "badge":"permaculturist",
        "badgee":"farmerthomas",
        "memo":"a good guy"
      }
    }
  ]
}
```

For testing an eosio signing request and QR code can be generated with web tools like
* https://github.com/greymass/eosio-uri-builder
* https://www.qrcode-monkey.com/

    
