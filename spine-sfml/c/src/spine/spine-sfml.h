/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated July 28, 2023. Replaces all prior versions.
 *
 * Copyright (c) 2013-2023, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software or
 * otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THE
 * SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef SPINE_SFML_H_
#define SPINE_SFML_H_

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <spine/extension.h>
#include <spine/spine.h>

_SP_ARRAY_DECLARE_TYPE(spColorArray, spColor)

namespace spine {

	class SkeletonDrawable : public sf::Drawable {
	public:
		spSkeleton *skeleton;
		spAnimationState *state;
		float timeScale;
		sf::VertexArray *vertexArray;

		SkeletonDrawable(spSkeletonData *skeleton, spAnimationStateData *stateData = 0);
		~SkeletonDrawable();

		void update(float deltaTime, spPhysics physics);

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		void setUsePremultipliedAlpha(bool usePMA) { usePremultipliedAlpha = usePMA; };
		bool getUsePremultipliedAlpha() { return usePremultipliedAlpha; };

	private:
		bool ownsAnimationStateData;
		float *worldVertices;
		spFloatArray *tempUvs;
		spColorArray *tempColors;
		spSkeletonClipping *clipper;
		bool usePremultipliedAlpha;
	};

} /* namespace spine */
#endif /* SPINE_SFML_H_ */
