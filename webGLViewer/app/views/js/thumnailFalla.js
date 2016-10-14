// Funcion que carga el codigo html del thumnail en la pagina.
(function(nameSpaceThumbnail,$,undefined){
  // $( document ).ready(function() {
       nameSpaceThumbnail.inicializar_thumnail = function(idFalla){
        $.get("app/views/html/thumbnail.html",function(data,status,jqxhttpresponse){
            if (status == "error") {
                console.log("Error cargando el thumnail: " + jqxhttpresponse.status +" "+
                  jqxhttpresponse.statusText);
                return; 
            }
            console.log("Exito cargando el thumnail" + status);
            $("#containerThumnail").append(data);
            configurar_thumnail();

            // Se solicita la generacion de la imagen y la descripcion para
            // el thumnail.
            solicitar_archivos_thumnail(idFalla);

        });
      }

      // Configura el comportamiento del thumnail.
      function configurar_thumnail(){
        $("[rel='tooltip']").tooltip();
        $('.thumbnail').hover(
            function(){
              $(this).find('.caption').slideDown(350); //.fadeIn(250)
            },
            function(){
              $(this).find('.caption').slideUp(250); //.fadeOut(205)
            }
        );
      }




      // Se cambia el estado del thumnail a cargando mientras se generan
      // los archivos .csv y .png del servidor.
      function solicitar_archivos_thumnail(idFalla){
        // Se modifica el estado del thumnail durante la carga
        $("#imagenThumb").attr("src","app/views/res/generandoArchivos.svg");
        window.nameSpaceCgi.transformarNubePtos(idFalla);
      }

  // });
}(window.nameSpaceThumbnail = window.nameSpaceThumbnail || {},jQuery));