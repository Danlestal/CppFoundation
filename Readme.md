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


2. Roadmap
2.1 Shooting.
    2.1.1 Actor spawn in real time
    2.1.2 Bullet Component, It should probably be a behaviour component
    2.1.3 Add a delay to the gun componet to avoid bullet spam
    2.1.4 Bullet actor destruction when it collides with something
    2.1.5 Deal with memory problems
    2.1.6 Bullet texture atlas
    2.1.7 Bullet animation.
    2.1.7 Improve texture management. Probably I need some kind of resource manager.

2.2 Invaders
    2.2.1 Review Invader Behaviour
    --->
    2.2.2 Add a new invader each time we kill one
    2.2.3 Try different movement patterns.
    2.2.4 Randomize the movement pattern.
    2.2.2 Add animation to invader

2.3 Explosions

2.3 Create a menu to choose different whiteboxes.

2.4 Play with different resolutions.
2.5.Music
2.6 First editor iteration

3. Things to review.
    Sospecho que tengo que cambiar todos lo pointes por smart_pointers. La pereza
    Seria interesante tener una clase SceneManager? Ahi metería el event manager y la scene. 
    Por ahora los métodos que tendria los he metido en la Factory.
    El concepto de SceneManager en cualquier caso es algo muy específico del juego, no del Engine.
    