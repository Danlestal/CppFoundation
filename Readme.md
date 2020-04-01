Template project v2.0
Following a more regular structure.

To run the tests:
make tester


1. Decisiones.

Voy a seguir una arquitectura estilo ECS. Gracias a esto puedo casi orientar todo el sistema a datos. En cualquier caso no estoy seguro que este tipo de arquitectura sea tan flexible como creo. Los componentes deberian ser puro dato.
Los delegates deberían utilizarse unicamente dentro de decoraciones de estos componentes, pero me da la sensacion que siguiendo esa aproximacion estoy complicando innecesariamente la estructura de clases.
Por ejemplo, BidimensionalComponent tiene que tener 2 delegates para recibir eventos de actualizacion y colision. Ambos delegates son unicamente utilizados para controlar las ordenes que llegan a la nave.
Al haberlos metido, estoy ensuciando el componente con métodos que solo utilizará la nave.

Me da la sensacion que esos 2 métodos deberían estar dentro de un behaviour component.

Toda comunicacion entre componentes se realiza a traves del EventManager. Esto tiene como consecuencia que en casi todos los delegates tendremos
que estar comprobando el id del actor. Por ahora creo que puedo vivir con ello.


Los sistemas tienen ahora una referencia a la escena. Suena lógico, porque basicamente los sistemas modifican el estado de la escena.


2. Hoja de ruta.
Ya soy capaz de disparar balas. Pero no se destruyen por algún problema con sus
físicas y ademas hay algun problema a la hora de crearlass :_(


2.1 Disparar balas.
    2.1.1 Spawn de actores en tiempo real
    2.1.2 Componente Bala, seguramente sea un componente behaviour.
    2.1.3 Añadir delay al componete GUN para evitar spawnear muchas balas.
--->
    2.1.4 Destruccion del actor bala cuando sale de las boundaries (esto va a empezar a hacer daño a nivel de memoria.)
    2.1.5 Atlas de texturas de la bala
    2.1.6 Animación de la bala

3.1 Marcianos
    


3. Cosas a revisar.
    Sospecho que tengo que cambiar todos lo pointes por smart_pointers. La pereza
    Seria interesante tener una clase SceneManager? Ahi metería el event manager y la scene. 
    Por ahora los métodos que tendria los he metido en la Factory.
    El concepto de SceneManager en cualquier caso es algo muy específico del juego, no del Engine.
    