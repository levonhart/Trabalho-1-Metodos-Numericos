double param_a = COEFICIENTE;

double _f(double d, double a){
	return a*exp(d) - 4*pow(d,2);
}
double _derivf(double d, double a){
	return a*exp(d) - 8*d;
}
double f(double d){
	return _f(d,param_a);
}
double derivf(double d){
	return param_a*exp(d) - 8*d;
}