#include <iostream>
using namespace std;
bool validar(string correo, string confirmar_correo);
bool confirmar(int pago);
void gen_factura(float pago, string nombre);
float descuento(float pago, float y);


int main()
{
    
    string nombre, correo, confirmar_correo;
    int cuenta, num_tel, opcion = 0, continuar, servicio, cantidad_pack, confirmar_num, total_packs = 0, respuesta = 0, opcion_pack;
    float pago, total, precio_pack, IVA = 0.15, total_descuento, rebaja=0.1;
    bool coincide;

    cout << "Bienvenido al servicio de call center de Tigo" << endl;
    do
    {
        bool correcto=false, correcto1=false;
        total = 0;
        do
        {
            
            
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
                correcto1=confirmar(pago);
            } while (correcto1==false);

            cout << "Se aplicara un IVA del 15% al monto ingresado" << endl;

            gen_factura(pago, nombre);

            
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
            do{
                cout << "Ingrese la cantidad de paquetes de datos que se desea comprar: ";
            cin >> cantidad_pack;
            correcto=confirmar(cantidad_pack);
            }while(correcto==false);
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
              total_descuento= descuento(total,rebaja);
            }
            cout << "Su total por " << cantidad_pack << " paquetes es: " << total_descuento << "$" << endl;

            do
            {

                cout << "Ingrese su correo para recibir los codigos de activacion de sus paquetes: ";
                cin >> correo;
                cout << "Vuelva a ingresar su correo: ";
                cin >> confirmar_correo;
                correcto = validar(correo, confirmar_correo);

            } while (correcto == false);

            cout << "Recibira los codigos de activacion de los paquetes al correo " << correo << " dentro de 1 hora junto con la informacion para realizar el pago";
            break;

        default:
            cout << "No ingreso una opcion valida, vuelva a intentarlo";
            break;
        }

        cout << "\nDesea realizar operacion? Si: 1 - No: (cualquier numero)" << endl;
        cin >> respuesta;

    } while (respuesta == 1);

    cout << "Gracias por contactarnos, tenga feliz dia";

    return 0;
}

bool validar(string correo, string confirmar_correo)
{
    bool coincide = false;

    if (correo == confirmar_correo)
    {
        cout << "Su correo fue confirmado" << endl;
        coincide = true;
    }
    else
    {
        cout << "Su correo no coincide, vuelva a intentarlo" << endl;
    }
    return coincide;
}
float descuento(float pago, float y)
{
    float total;

    total = pago * (1 - y);
    return total;
}

bool confirmar(int x)
{

bool valido= false;
int intento=1;
    if (x < 0)
    {

        cout << "La cantidad ingresada no es valida, porfavor vuelva a intenarlo" << endl;
        intento++;
        if (intento == 3)
        {
            cout << "Ha excedido el numero de inentos, reinicie la sesion para poder continuar";

            exit(1);
        }
    }else {
        valido=true;
    }
    return valido;
    
}
void gen_factura(float pago, string nombre){
    float total, IVA=0.15;
    total = pago * (IVA + 1);
            cout << "Esta es su factura: " << endl;
            cout << "\n*****FACTURA******" << endl;
            cout << "Cliente a pagar: " << nombre << endl;
            cout << "Total a pagar: " << total << endl;
            cout << "Puede realizar el pago por el metodo de su preferencia con fecha limite dentro de 30 dias";
}
