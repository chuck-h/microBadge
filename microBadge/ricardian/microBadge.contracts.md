<h1 class="contract">init</h1>

---
spec_version: "0.1.0"
title: init
summary: '{{init}} posts badge info by issuer'
icon: 
---

Default semantics: init is the first blockchain entry assigning a particular badge to a particular badgee account. If earlier blockchain entries exist regarding this badge and badgee, the init action renders them obsolete and they should be ignored.

<h1 class="contract">issuerupdate</h1>

---
spec_version: "0.1.0"
title: issuerupdate
summary: '{{issuerupdate}} posts badge info by issuer'
icon: 
---

Default semantics: issuerupdate adds information about a badgee in the memo field. The new information is attested by the issuer. Interpretation is application-dependent; new information may add to, or replace, earlier information.

<h1 class="contract">cancel</h1>

---
spec_version: "0.1.0"
title: cancel
summary: '{{cancel}} posts badge cancelation by issuer'
icon: 
---

Default semantics: cancel indicates that the badge is no longer applicable.

<h1 class="contract">badgeeupdate</h1>

---
spec_version: "0.1.0"
title: badgee_update
summary: '{{badgeeupdate}} posts badge info by badgee'
icon: 
---

Default semantics: badgeeupdate adds information about a badgee in the memo field. The new information is attested by the badgee. Interpretation is application-dependent; new information may add to, or replace, earlier information.


<h1 class="contract">badgeereject</h1>

---
spec_version: "0.1.0"
title: init
summary: '{{badgeereject}} posts badge rejection by badgee'
icon: 
---

Default semantics: badgeereject indicates that the badgee does not wish to hold the badge. In a membership case the issuer would typically respond by cancelling the badge. In other cases the behavior is application-dependent.
