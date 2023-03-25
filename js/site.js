function loadPage(filename) {
    window.location.href = filename
}

function highlight(filename) {
    let link = $("[onclick=\"loadPage('" + filename + "')\"]");
    if (link && link.length > 0) {
        link.parent().attr("class", "list-group-item list-group-item-warning");
        link.prepend("<i class='fa fa-circle' style='position: relative; left: -1rem;'></i>");
        link.removeClass("text-primary");
        let return_button = $(".button-return");
        return_button.html("<i class='fa fa-lg fa-times'></i>").attr("onclick", "loadPage('" + filename + "')");
    } else {
        setTimeout(function () {
            highlight(filename);
        }, 10);
    }
}

/* Standard C Library */
function isalpha(ch) {
    return /^[A-Z]$/i.test(ch);
}

function isdigit(ch) {
    return /^[0-9]$/i.test(ch);
}

const NULL = null;

function atoi(s) {
    return parseInt(s);
}

function strlen(s) {
    return parseInt(s.length);
}

function strcasestr(big, little) {
    const i = big.toLowerCase().indexOf(little.toLowerCase());
    return (i !== -1) ? i : NULL;
}

function strchr(str, char) {
    if (typeof str == "string" && typeof char == "string" && char.length == 1) {
        return str.indexOf(char);
    } else {
        return NULL;
    }
}