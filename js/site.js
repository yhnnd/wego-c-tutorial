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