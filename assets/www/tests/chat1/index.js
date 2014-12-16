var self = this;

function send(content) {

    'use strict';
    var area = document.getElementById('chat1_area');
    area.innerHTML = area.innerHTML + '#me: ' + content + '\n';
    self.sendMessage('chat', content);
};

this.onmessage = function (info, content) {

    'use strict';

    console.log('message from', info.from, content);
    var area = document.getElementById('chat1_area');
    area.innerHTML = area.innerHTML + '#from: ' + content + '\n';
};

this.chat_click = function () {

    'use strict';

    var input = document.getElementById('chat1_text_entry');
    if (input === undefined) return;
    send(input.value);
    input.value = '';
};

this.chat_keypress = function (event) {
    var evt = event || window.event;
    var charCode = evt.keyCode || evt.which;
    if (charCode == 13) {
        self.chat_click();
    }
};

module.ui.display('ui/index.tmpl');
