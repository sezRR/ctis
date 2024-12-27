$(function(){
    let list = [] ;
    $("button").on("click", function(){
        $(this).remove() ;
        $(".item").each(function(){
            let item = {} ;
            item.completed = $(this).find("span:first").text() == "completed"  ;
            item.text = $(this).find("h3").text() ;
            item.order = Number($(this).find(".order").text()) ;
            list.push(item) ;
        })
        list.sort( (a,b) => a.order - b.order)
        let out = "<h1>Todo List</h1>" ;
        for (let it of list) {
            out += `<div class='todo-item'><span>${it.order}</span>` ;
            out += `<em class='${ it.completed ? 'line-through' : '' }'>${it.text}</em>` ;
            out += `<img src='delete.svg'></div>` ;
        } 
        $("#todos").html(out)
        $("#todos").on("click", "div", function(){
            $(this).find("em").toggleClass("line-through") ;
        }).on("click" ,"img", function(e){
           e.stopPropagation() ;
           $(this).parent().fadeOut(500, function() { 
              $(this).remove()
              $(".todo-item").each(function(i){
                $(this).find("span").text(i+1)
              })
            })
        })
    })
})