$(document).ready(() => {
    $("button").on("click", function () {
        // Scrape todos
        const todos = []
        $("#todos .item").each(function (i) {
            const todo = $(this).children("h3").text();
            const isCompleted = $(this).children("span:first").text().length ? true : false;
            const order = parseInt($(this).children(".order").text())
            todos.push({ todo, isCompleted, order })
        })
        todos.sort((a, b) => a.order - b.order)

        // Delete old UI
        $(this).remove()
        $("#todos").empty()

        // Apply New UI
        $("#todos").addClass("container")
        $("body").prepend("<h1>Todo List</h1>")
        todos.forEach(todo => {
            $("#todos").append(`
                <div class="todo">
                    <span>${todo.order}</span>
                    <span class="description">${todo.todo}</span>
                    <span class="btn-delete"></span>
                </div>
            `)
        })

        $(".btn-delete").load("./delete.svg")
    });

    $("#todos").on("click", ".todo", function () {
        $(this).children(":nth-child(2)").toggleClass("completed")
    })

    $("#todos").on("click", ".btn-delete", function (e) {
        e.stopPropagation()
        $(this).parent().fadeOut()
    })
})