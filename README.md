# Sensores_de_distancia
Un sensor de distancia permite realizar la medida de distancia o desplazamiento entre el propio sensor y un
objeto en frente de él una forma automatizada, y proporciona una señal eléctrica según la variación física de
distancia. Dependiendo de lo sofisticado que sea el sensor, la señal eléctrica puede ser analógica con una
variación de tensión o corriente, digital en forma de pulsos de un tiempo de terminado, o de datos serie.  

Esta práctica se trabajará con dos tipos de sensores de distancia muy utilizados en robótica: los que utilizan
ultrasonidos y los basados en la reflexión de la luz. En concreto, se experimentará con dos sensores de
ultrasonidos, uno de categoría industrial y otro económico, y con un sensor óptico de reflexión económico.

Para estudiar el funcionamiento de los sensores, cada uno de ellos se conectará a un Arduino Uno que será
programada para aplicar la curva de calibración del sensor y proporcionar un valor de distancia en metros. La
curva de calibración es la función que relaciona la distancia medida por el señor con la señal eléctrica que
proporciona. Después, se realizará un conjunto de medidas de la distancia entre cada sensor y dos objetos
determinados, de materiales diferentes, para comparar la exactitud y repetitividad de los tres sensores entre
sí. Las medidas serán enviadas por Arduino al ordenador mediante la comunicación serie‐USB, en formato CSV,
de forma que puedan ser fácilmente guardadas en archivos y analizadas con una hoja de cálculo. Finalmente,
analizando el funcionamiento de los sensores y la comparación de sus características antes distintos objetos,
se concluirá para que tipo de aplicación es más adecuado cada sensor. 
