/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:50:48 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/20 17:31:53 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.h"
#include "AMateria.h"
#include <string>
#include <cstdlib>

MateriaSource::MateriaSource()
    : m_materiaCount(0)
{
    for (int i = 0; i < 4; ++i)
        m_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
    : m_materiaCount(other.m_materiaCount)
{
    for (int i = 0; i < 4; ++i)
        m_materias[i] = other.m_materias[i] ?
            other.m_materias[i]->clone() : NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < m_materiaCount; ++i)
        if (m_materias[i])
            delete m_materias[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < m_materiaCount; ++i)
            if (m_materias[i])
                delete m_materias[i];
        m_materiaCount = rhs.m_materiaCount;
        for (int i = 0; i < m_materiaCount; ++i)
            m_materias[i] = rhs.m_materias[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m_materiaCount < 4 && m)
        m_materias[m_materiaCount++] = m;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < m_materiaCount; ++i)
    {
        if (m_materias[i] && m_materias[i]->getType() == type)
            return m_materias[i]->clone();
    }
    return NULL;
}