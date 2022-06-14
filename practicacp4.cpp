#include <iostream>
using namespace std;

int main()
{
    string nombre, correo, confirmar_correo;
    int cuenta, num_tel, opcion = 0, continuar, servicio, cantidad_pack, confirmar_num, total_packs = 0, intento = 0, respuesta = 0, opcion_pack;
    float pago, total, precio_pack, IVA = 0.15;
    bool coincide;

    cout << "Bienvenido al servicio de call center de Tigo" << endl;
    do
    {
        do
        {
            total = 0;
            cout << "Ingresa la operacion que deseas realizar: " << endl;
            cout << "1: Facturacion de servicio -  2:Solicitud cambio de numero - 3:Compra de paquete de datos " << endl;
            cin >> opcion;

        } while (opcion < 1 || opcion > 4);

        switch (opcion)

        {

        case 1:
            cout << "Te estas contactando con el servicio facturacion" << endl;
            cout << "Ingresa el nombre completo del cliente a facturar (separado por guiones): " << endl;
            cin >> nombre;
            do
            {

                cout << "Ingresa la cantidad a pagar: " << endl;
                cin >> pago;
                if (pago < 0)
                {

                    cout << "La cantidad ingresada no es valida, porfavor vuelva a intenarlo" << endl;
                    intento++;
                    if (intento == 3)
                    {
                        cout << "Ha excedido el numero de inentos, reinicie la sesion para poder continuar";

                        exit(1);
                    }
                }

            } while (pago < 0);

            cout << "Se aplicara un IVA del 15% al monto ingresado" << endl;
            total = pago * (IVA + 1);
            cout << "Esta es su factura: " << endl;
            cout << "*****FACTURA******" << endl;
            cout << "Cliente a pagar: " << nombre << endl;
            cout << "Total a pagar: " << total << endl;
            cout << "Puede realizar el pago por el metodo de su preferencia con fecha limite dentro de 30 dias";
            break;

        case 2:
            cout << "Se esta contactando con el servicio tecnico" << endl;
            do
            {
                cout << "Ingrese el motivo por el cual desea cambiar de numero: " << endl;
                cout << "1: Chip extraviado - 2: Chip averiado - 3: Problemas de privacidad - 4:Otro" << endl;
                cin >> respuesta;
            } while (respuesta < 0 || respuesta > 4);

            for (int i = 0; i <= 3; i++)
            {

                cout << "Ingrese su numero: ";
                cin >> num_tel;
                cout << "Confirme su numero de telefono: ";
                cin >> confirmar_num;
                if (num_tel == confirmar_num)
                {
                    break;
                }
                if (i == 3)
                {
                    cout << "Supero el numero de intentos, reinice la sesion para poder continuar";
                    exit(1);
                }
            }
            cout << "El proceso para su cambio de numero se ha inicado, puede pasar por las oficinas para recoger su nuevo chip dentro de 2 dias habiles";
            break;

        case 3:
            cout << "Se esta contactando con el servicio de ventas" << endl;
            cout << "Ingrese la cantidad de paquetes de datos que se desea comprar: ";
            cin >> cantidad_pack;
            cout << "Estas son las opciones disponibles: " << endl;
            cout << "Paquete 1: 3gb de datos + 60 mins de llamadas a 5$" << endl;
            cout << "Paquete 2: 5gb de datos + 45 mins de llamadas a 6$" << endl;
            cout << "Paquete 3: 2gb de datos + 120 mins de llamadas a 4$" << endl;
            do
            {
            salto:
                cout << "Ingrese el numero del paquete que desea comprar: ";
                cin >> opcion_pack;

                switch (opcion_pack)
                {
                case 1:
                    precio_pack = 5;
                    break;
                case 2:
                    precio_pack = 6;
                    break;

                case 3:
                    precio_pack = 4;

                    break;

                default:
                    cout << "No ingreso una opcion valida, vuelva a intentarlo" << endl;
                    goto salto;
                    break;
                }
                total += precio_pack;
                total_packs++;
            } while (total_packs != cantidad_pack);
            if (total > 10)
            {
                cout << "Su compra es mayor a 10 dolares, recibira un descuento del 10% en su total" << endl;
                total *= 0.9;
            }
            cout << "Su total por " << cantidad_pack << " paquetes es: " << total << "$"<<endl;
            do
            {
                confirmacion: 
                cout << "Ingrese su correo para recibir los codigos de activacion de sus paquetes: ";
                cin >> correo;
                cout << "Vuelva a ingresar su correo: ";
                cin >> confirmar_correo;

                if (correo == confirmar_correo)
                {
                    coincide = true;
                    continue;
                }
                else
                {
                    cout << "Su correo no coincide con el anterior, vuelva a intentarlo" << endl;
                    goto confirmacion;
                }
            } while (coincide == false);

                cout<<"Recibira los codigos de activacion de los paquetes al correo "<<correo<<" dentro de 1 hora junto con la informacion para realizar el pago";
            break;
        }
        cout << "\nDesea realizar operacion? Si: 1 - No: (cualquier numero)" << endl;
        cin >> respuesta;

    } while (respuesta == 1);

    cout << "Gracias por contactarnos, tenga feliz dia";
    return 0;
}