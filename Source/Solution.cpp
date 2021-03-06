//     aRCPLan
//     Copyright (c) [2014] [Fraser Edwards][Dr Patrick Leevers]
//     aRCPlan may be freely distributed under the MIT license.
//     For the underlying model, see http://www.sciencedirect.com/science/article/pii/S0013794412003530

//     Class which collects solution values in to one object for easy storage and access
//     Collects solution values as well as crack profiles for access later

#include <iostream>
#include <iomanip>

#include "Solution.h"

//Null constructor
Solution::Solution()
{

    soln=0;
    adotc0.push_back(0.0);
    p0bar.push_back(0.0);
    tempdegc.push_back(0.0);
    z.push_back(0.0);
    k=0;

    decompression.push_back(0.0);
    alpha.push_back(0.0);
    m.push_back(0.0);
    outflow_length.push_back(0.0);
    deltadstar.push_back(0.0);
    gs1.push_back(0.0);
    gue.push_back(0.0);
    gsb.push_back(0.0);
    gkb.push_back(0.0);
    gg0.push_back(0.0);
    gtotal.push_back(0.0);
    g0.push_back(0.0);
    no_crack_opening.push_back(1);
    not_converged.push_back(1);
    iterations.push_back(0);

}

//Clears all values within the solution class and resizes their arrays to 1
void Solution::clear()
{
    soln=0;
    k=0;
    adotc0.clear();
    adotc0.resize(1);
    p0bar.clear();
    p0bar.resize(1);
    tempdegc.clear();
    tempdegc.resize(1);
    z.clear();
    z.resize(1);
    w.clear();
    w.resize(1);

    decompression.clear();
    decompression.resize(1);
    alpha.clear();
    alpha.resize(1);
    m.clear();
    m.resize(1);
    outflow_length.clear();
    outflow_length.resize(1);
    deltadstar.clear();
    deltadstar.resize(1);
    gs1.clear();
    gs1.resize(1);
    gue.clear();
    gue.resize(1);
    gsb.clear();
    gsb.resize(1);
    gkb.clear();
    gkb.resize(1);
    gg0.clear();
    gg0.resize(1);
    gtotal.clear();
    gtotal.resize(1);
    g0.clear();
    g0.resize(1);
    no_crack_opening.clear();
    no_crack_opening.resize(1);
    not_converged.clear();
    not_converged.resize(1);
    iterations.clear();
    iterations.resize(1);

}

//Sets up displacement values for crack profiles
void Solution::displacement(Parameters &parameters)
{
    n = (parameters.elements_in_l * (parameters.lambda+2))+1;
    vector<double> row;

    //Creates column (used as row) vector
    for(i = 0; i < n; i++ )
    {
        row.push_back(0.0);
    }
    //Stores vector in vector to provide a "Matrix"
    for(i = 0; i < parameters.range_number; i++)
    {
        w.push_back(row);
    }
    //Generates displacement for crack profile
    for(i = 1; i < n; i++)
    {
        z.push_back(double(i)/double(parameters.elements_in_l));
    }

}

//Collects the crack profile for each solution, writing it to the
//already created matrix
void Solution::collectProfile(const vector<double> vptras, const int ls)
{
    k++;
    //Read values from input crack profile and writes to the matrix
    for(i = 0; i <= ls; i++)
    {
        w[k][i]=vptras[i];
    }

}

//Collects the values from the arguments provided, storing them into
//a single solution object
void Solution::collect(const double adotc0s, const double p0bars, const double tempdegcs, const double decompressions, const double alphas, const double ms, const double outflow_lengths, const double deltadstars,
                            const double gs1s, const double gues, const double gsbs, const double gkbs, const double g0s, const double gg0s, const double gtotals, const short no_crack_openings, const short not_convergeds, const short iterationss)
{
	soln++;
    adotc0.push_back(adotc0s);
    p0bar.push_back(p0bars);
    tempdegc.push_back(tempdegcs);

	decompression.push_back(decompressions);
	alpha.push_back(alphas);
	m.push_back(ms);
    outflow_length.push_back(outflow_lengths);
    deltadstar.push_back(deltadstars);
    gs1.push_back(gs1s);
    gue.push_back(gues);
    gsb.push_back(gsbs);
    gkb.push_back(gkbs);
	g0.push_back(g0s);

    //Flips values so that they make sense under the headings of the tables
    no_crack_opening.push_back(!no_crack_openings);
    not_converged.push_back(!not_convergeds);
    iterations.push_back(iterationss);

    //Removes spurious errors, need to find source of these
    if (gg0s < 1000)
    {gg0.push_back(gg0s);}
    else
    {gg0.push_back(0.0);}

    if (gtotals < 1000)
    {gtotal.push_back(gtotals);}
    else
    {gtotal.push_back(0.0);}
	
}
