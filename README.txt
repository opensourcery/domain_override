$Id: README.txt,v 1.3 2010/11/18 22:22:46 bikko Exp $

/**
 * @file
 * README file for Domain Override.
 */

Domain Override
===============

Allows overriding page nodes on a domain-specific basis.


Features
--------
* Provides an "Override" tab on node pages that removes the current domain from the node's domain access, clones the node, and publishes the clone to only the current domain.
* Sidesteps need to use multiple `url_alias` tables (with Domain Prefix). Makes Drupal interpret the URL alias for a node that's been overridden as a path to this domain's version of the node. Example: node 1 (the node at `node/1`) is published to all domains with the URL alias `contact-us`. You visit the node from the subdomain "cats" and select the "Override" tab. Now a new node has been created (node 2), that's published only to the "cats" subdomain, and node 1 is no longer published to the "cats" subdomain. When you visit `http://site/contact-us` you'll see the content of node 1. However, when you visit `http://cats.site/contact-us`, you'll see the content of node 2 -- node 1's override.


Requirements
------------
* Drupal 6.x
* Domain Access (domain)
* (Recommendation) URL Alter (url_alter)


Installation
------------
Install like any other contrib module. Read more about installing modules at http://drupal.org/node/70151.


Notes
-----
* Domain Override implements `custom_url_rewrite_inbound()`, or implements it as a hook if url_alter module is installed.
* This module does nothing to transform (override) node reference fields or which nodes are selected by Views.
* When you've viewing an overridden page (e.g. `http://cats.site/contact-us`), you may notice that, though your browser is at the `/contact-us` URL, the node's View tab links to `/node/2` (that is, directly to the overridden node). This is expected behavior. How exactly this could be changed -- what behavior would be "better" -- seems like a big, loaded question.
* There's no way to remove (or manually create) entries in the `domain_override` database table. This is the database table that tracks which nodes are overrides of other nodes, and for which domain.


Troubleshooting
---------------
    Error message "Fatal error: Cannot redeclare custom_url_rewrite_inbound()"
This problem may also manifest as a WSOD (white screen of death).

* Problem:  There's already a module installed that provides the `custom_url_rewrite_inbound()` function.
* Solution: Install the url_alter module.


Author
------
The **Domain Override** module is developed and maintained by [OpenSourcery](http://opensourcery.com).

