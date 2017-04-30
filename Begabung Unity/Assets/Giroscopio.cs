using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class Giroscopio : MonoBehaviour {
	public int y;
	public int z;
	public int x;
	SerialPort serial = new SerialPort("COM3", 115200);

	// Use this for initialization
	void Start () {
		serial.Open ();
		serial.ReadTimeout = 2000;
	}
	
	// Update is called once per frame
	void Update () {
		if (!serial.IsOpen)
			serial.Open ();

		serial.Write ("a");
		float AcX = float.Parse (serial.ReadLine ());
		serial.Write ("b");
		float AcY = float.Parse (serial.ReadLine ());
		serial.Write ("c");
		float AcZ = float.Parse (serial.ReadLine ());
		//serial.Write ("d");
		//float GyX = int.Parse (serial.ReadLine ());
		//serial.Write ("e");
		//float GyY = int.Parse (serial.ReadLine ());
		//serial.Write ("f");
		//float GyZ = int.Parse (serial.ReadLine ());


		//x = AcX / 109;
		// += GyY / 3000;
		//z += GyX / 3000;

		transform.localEulerAngles = new Vector3 (AcZ, AcY, AcX);

	}
}
