var HOST= "localhost";
var PHPFOLDER = "/tkinect2016/webGLViewer/app/helpers/generar_csv_php/generar_csv.php";


fallaMostrada = false;
function configurar_info_falla(){
	// Configuracion del alert
	$('#error-alert').attr("class","alert alert-danger alert-dismissible fade");

	// Confinguracion del boton
	$('#boton-info').attr('data-loading-text',"Cargando info...");	

}


// Invoca al generador.php que retorna un json al .csv que escribio.
function generar_propiedades_falla_csv(carpetaFalla){
	// Se llama a un .php que genere un csv con las propiedades que se mostraran en la falla
	$.get("http://"+HOST+PHPFOLDER+"?carpeta="+carpetaFalla,function(data){
		// El php genera un csv en un directorio por defecto y retorna un JSON
		// con la URL del csv en el servidor.
		//  { "pathCsv": "http://localhost/tkinect2016/data/pointcloud_1/test.csv" }

		var json = JSON.parse(data);
		debug("La url obtenida es -->");
		debug(json.pathCsv);
		debug("");
		cargar_cvs_falla(json.pathCsv);
	});

}


// Declaracion y ejecucion de funcion de js
var json_csv;
var NOMBRE_CSV_INFO_FALLA = "test.csv";
function debug(msg){
	console.log(msg);
}

// Funcion para el parseo de CSV
function cargar_cvs_falla(url){
	// var PATH_CSV = "js/tablaCVS/lib/test.csv"; 
	Papa.parse(url, {
		download: true,
		complete: function(data)
		{
			debug("CSV Parseado!!");
			debug(data);
			json = transformar_a_json(data.data);
			debug("El json obtenido fue: ");
			debug(json);
			generar_datos_falla(json);
			setTimeout(function(){
				$('#boton-info').button('reset');
			}, 3000);
		},
		error: function(data)
		{
			debug("mdamdkamdkasm");
			$('#error-alert').attr('style','display:inline;');
			$('#error-alert').attr("class","alert alert-danger alert-dismissible in");
			setTimeout(function(){
				$('#error-alert').attr("class","alert alert-danger alert-dismissible fade");
				}, 3000);
			$('#boton-info').button('reset');
		}
	});
}

// Elegir la primera linea con el nombre de las propiedades
// y la segunda con los valores de las propiedades y produce un json
function transformar_a_json(data){
	debug("Los datos obtenidos son: ");
	debug(data);
	nombresPropiedades=data[0];
	valoresPropiedades=data[1];
	result = {};
	for (var i = 0; i < nombresPropiedades.length; i++) {
			result[ nombresPropiedades[i] ] = valoresPropiedades[i];
	};
	return result;
}

// Muestra la informacion de una falla en un componente de Bootstrap
// a partir de un json
function generar_datos_falla(data_json){
	$('#datos-falla').append('<dl id="tablaHorizontal" class="dl-horizontal" style="position:absolute;left:65%;top:17%;"></dl>');
	$.each(data_json, function(key,valorProp){
		var nombreProp = key.toString();
	 	// Agregar las filas para cada elemento del json.
	 	$('#tablaHorizontal').append('<dt>'+nombreProp+'</dt>');
	 	$('#tablaHorizontal').append('<dd>'+valorProp+'</dd>');
	});
}

function limpiar_container(){

	$('#tablaHorizontal').remove();
}


 //    if ( ! Detector.webgl ) Detector.addGetWebGLMessage();

 //    var container, stats;
	// var camera, controls, scene, renderer;

	// init();
	// animate();
	// function init() {

	// 	scene = new THREE.Scene();

	// 	camera = new THREE.PerspectiveCamera( 15, window.innerWidth / window.innerHeight, 0.01, 40 );
	// 	camera.position.x = 0.4;
	// 	camera.position.z = -5;
	// 	// camera.position.z = -2;
	// 	camera.up.set(0,0,1);

	// 	controls = new THREE.TrackballControls( camera );

	// 	controls.rotateSpeed = 2.0;
	// 	controls.zoomSpeed = 0.3;
	// 	controls.panSpeed = 0.2;

	// 	controls.noZoom = false;
	// 	controls.noPan = false;

	// 	controls.staticMoving = true;
	// 	controls.dynamicDampingFactor = 0.3;

	// 	controls.minDistance = 0.3;
	// 	controls.maxDistance = 0.3 * 100;

	// 	scene.add( camera );

	// 	var axisHelper = new THREE.AxisHelper( 0.1 );
	// 	scene.add( axisHelper );

	// 	renderer = new THREE.WebGLRenderer( { antialias: true } );
	// 	renderer.setClearColor( 0x000000 );
	// 	renderer.setPixelRatio( window.devicePixelRatio );
	// 	renderer.setSize( 800, 385);
	// 	document.body.appendChild( renderer.domElement );
		

	// 	var loader = new THREE.PCDLoader();

	// 	var RUTA_PCD = './models/pcd/'
	// 	var NOMBRE_ARCHIVO =  'prueba6.pcd'
	// 	loader.load( RUTA_PCD + NOMBRE_ARCHIVO, function ( mesh ) {

	// 		scene.add( mesh );
	// 		var center = mesh.geometry.boundingSphere.center;
	// 		controls.target.set( center.x, center.y, center.z);
	// 		controls.update();

	// 	} );

	// 	container = document.createElement( 'div' );
	// 	container.setAttribute('class','container-ajustado');
	// 	// $("#tablaCVS").append(container);
	// 	document.body.appendChild( container );
	// 	container.appendChild( renderer.domElement );
		

	// 	// stats = new Stats();
	// 	// container.appendChild( stats.dom );

	// 	window.addEventListener( 'resize', onWindowResize, false );

	// 	// window.addEventListener('keydown', keyboard);
	// }

	// function onWindowResize() {

	// 	camera.aspect = window.innerWidth / window.innerHeight;
	// 	camera.updateProjectionMatrix();
	// 	renderer.setSize( window.innerWidth, window.innerHeight );
	// 	controls.handleResize();

	// }

	// // function keyboard ( ev ) {

	// // 	var ZaghettoMesh = scene.getObjectByName( "Zaghetto.pcd" );

	// // 	switch ( ev.key ) {

	// // 		case '+':
	// // 			ZaghettoMesh.material.size*=1.2;
	// // 			ZaghettoMesh.material.needsUpdate = true;
	// // 			break;

	// // 		case '-':
	// // 			ZaghettoMesh.material.size/=1.2;
	// // 			ZaghettoMesh.material.needsUpdate = true;
	// // 			break;

	// // 		case 'c':
	// // 			ZaghettoMesh.material.color.setHex(Math.random()*0xffffff);
	// // 			ZaghettoMesh.material.needsUpdate = true;
	// // 			break;

	// // 	}

	// // }

	// function animate() {

	// 	requestAnimationFrame( animate );
	// 	controls.update();
	// 	renderer.render( scene, camera );
	// 	// stats.update();

	// }

