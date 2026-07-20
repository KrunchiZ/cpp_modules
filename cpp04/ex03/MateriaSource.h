/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:50:48 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/20 18:28:24 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"

class AMateria;

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& rhs);
    
    virtual ~MateriaSource();
    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(const std::string& type);

private:
    AMateria* m_materias[4];
    int m_materiaCount;
};

#endif