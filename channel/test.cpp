/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:02:41 by haitaabe          #+#    #+#             */
/*   Updated: 2026/04/07 11:09:14 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>



int main()
{
    std::map<int , std::string> Ppl = {{1, "Hamza"}, {2, "Aitaabella"},{3, "1337"}};

    for (auto &P : Ppl)
    {
        std::cout << P.first << " " << P.second << std::endl;
    }
}