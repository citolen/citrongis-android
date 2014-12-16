Extension ZIP compression

    /
        /ui           -  optional
            /js
            /css
            /view
        /src            -  optional
        package.json    - *required*
        strings.json    -  optional


package.json:
```
{
    "name": "unique application name", - *required*
    "version": "0.123", - *required*
    "main": "src/main.js", - optional; default: src/main.js
    "dependencies": optional
    [
        {
            "name": "dependency name",          - *required*
            "version": "dependency version"     - optional
        },
        ...
    ]
}
```

strings.json:
```
{
    "fr":
    {
        "APPLICATION_NAME": "citrongis",
        "PROPERTY": "value"
    }
    "default":
    {
        "PROPERTY": "value"
    }
}
```

code:

    strings["property"] will return according to system localization
    
    
    
    
    
Extension Context

```

=== Extension Loader ===


=== Context === // Internal object to manage extensions

context.module  // Module object
context.handle // Zip handler
context.package // package info


=== Module === // Object seen by developer

module.exports =    // export d'un object
module.strings =    // strings.json
module.ui =         // UI object
module.global = {}  // empty object to fill with property you wanna expor to interfaces

=== UI ===

UI.current  // current document visible
UI.display('path', { data })    // Display an other document

-C
    -Extension
                -UI
                    include
        

=== Include Script ===

    <% include('pathtoscript.js'); %>
    
=== Function ===

    <%= function('name'); %>
    
    
    (function(arg_to_pass) {
        //extension code
    })(arg_to_pass);



```